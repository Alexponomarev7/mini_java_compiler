#include "irtree_build_visitor.h"

#include <components/program.h>

#include "types/integer.h"
#include "types/types.h"

#include <iostream>

void IrtreeBuildVisitor::Visit(Program* program) {
    for (const auto& classObj : program->classes_) {
        classObj->Accept(this);
    }

    current_frame_ = new IRT::FrameTranslator("main");
    frame_translator_["main"] = current_frame_;

    current_frame_->AddReturnAddress();

    auto statements_ir = Accept(program->main_);

    if (statements_ir) {
        tos_value_ = new IRT::StatementWrapper(
            new IRT::SeqStatement(
                new IRT::LabelStatement(IRT::Label("main")),
                statements_ir->ToStatement() // TODO: set return value 0 by default
            )
        );
    } else {
        // generating return 0
        tos_value_ = new IRT::StatementWrapper(
            new IRT::SeqStatement(
                new IRT::LabelStatement(IRT::Label("main")),
            new IRT::MoveStatement(
                    current_frame_->GetReturnValueAddress()->ToExpression(),
                    new IRT::ConstExpression(0)
                )
            )
        );
    }

    method_trees_.emplace("main", tos_value_->ToStatement());
}

void IrtreeBuildVisitor::Visit(MainClass* mainClass) {
    auto scope_statements = new ScopeStatements(mainClass->statements_);
    tos_value_ = Accept(scope_statements);
}

void IrtreeBuildVisitor::Visit(Class* classObj) {
    for (const auto& declaration : classObj->declarations_) {
        declaration->Accept(this);
    }
}

void IrtreeBuildVisitor::Visit(Formal* formal) {
    // pass
}

void IrtreeBuildVisitor::Visit(MethodInvocation* methodInvocation) {
    auto irt_expressions = new IRT::ExpressionList();

    for (auto it: methodInvocation->params_) {
        auto simpleExpression = new SimpleExpression(it);
        irt_expressions->Add(Accept(simpleExpression)->ToExpression());
    }

    tos_value_ = new IRT::ExpressionWrapper(
        new IRT::CallExpression(
            new IRT::NameExpression(IRT::Label(methodInvocation->id_)),
            irt_expressions
        )
    );
}

void IrtreeBuildVisitor::Visit(VariableDeclaration* variableDeclaration) {
    if (current_frame_ != nullptr) {
        current_frame_->AddLocalVariable(variableDeclaration->id_);
    }

    tos_value_ = nullptr;
}

void IrtreeBuildVisitor::Visit(MethodDeclaration* methodDeclaration) {
    current_frame_ = new IRT::FrameTranslator(methodDeclaration->id_);
    frame_translator_[methodDeclaration->id_] = current_frame_;

    for (auto param : methodDeclaration->formals_) {
        current_frame_->AddArgumentAddress(param->id_);
    }

    current_frame_->AddReturnAddress();

    auto scope_statements = new ScopeStatements(methodDeclaration->statements_);
    auto statements_ir = Accept(scope_statements);

    if (statements_ir) {
        tos_value_ = new IRT::StatementWrapper(
                new IRT::SeqStatement(
                        new IRT::LabelStatement(IRT::Label(methodDeclaration->id_)),
                        statements_ir->ToStatement() // TODO: set return value 0 by default
                )
        );
    } else {
        // generating return 0
        tos_value_ = new IRT::StatementWrapper(
                new IRT::SeqStatement(
                        new IRT::LabelStatement(IRT::Label(methodDeclaration->id_)),
                        new IRT::MoveStatement(
                                current_frame_->GetReturnValueAddress()->ToExpression(),
                                new IRT::ConstExpression(0)
                        )
                )
        );
    }

    method_trees_.emplace(methodDeclaration->id_, tos_value_->ToStatement());
}

void IrtreeBuildVisitor::Visit(ArrayMakeExpression* arrayMakeExpression) {
    // pass
}

void IrtreeBuildVisitor::Visit(BinaryExpression* binaryExpression) {
    auto leftResult = Accept(binaryExpression->leftExpr_);
    auto rightResult = Accept(binaryExpression->rightExpr_);

    IRT::BinaryOperatorType IROperator;
    if (binaryExpression->binaryOperator_ == "+") {
        IROperator = IRT::BinaryOperatorType::PLUS;
    } else if (binaryExpression->binaryOperator_ == "-") {
        IROperator = IRT::BinaryOperatorType::MINUS;
    } else if (binaryExpression->binaryOperator_ == "*") {
        IROperator = IRT::BinaryOperatorType::MUL;
    } else if (binaryExpression->binaryOperator_ == "/") {
        IROperator = IRT::BinaryOperatorType::DIV;
    } else if (binaryExpression->binaryOperator_ == "%") {
        IROperator = IRT::BinaryOperatorType::MOD;
    } else if (binaryExpression->binaryOperator_ == "&&") {
        tos_value_ = new IRT::AndConditionalWrapper(
            leftResult,
            rightResult
        );
        return;
    } else if (binaryExpression->binaryOperator_ == "||") {
        tos_value_ = new IRT::OrConditionalWrapper(
            leftResult,
            rightResult
        );
        return;
    } else if (binaryExpression->binaryOperator_ == "==") {
        tos_value_ = new IRT::RelativeConditionalWrapper(
                IRT::LogicOperatorType::EQ,
                leftResult->ToExpression(),
                rightResult->ToExpression()
        );
        return;
    } else if (binaryExpression->binaryOperator_ == "<") {
        tos_value_ = new IRT::RelativeConditionalWrapper(
            IRT::LogicOperatorType::LT,
            leftResult->ToExpression(),
            rightResult->ToExpression()
        );
        return;
    } else if (binaryExpression->binaryOperator_ == ">") {
        tos_value_ = new IRT::RelativeConditionalWrapper(
            IRT::LogicOperatorType::GT,
            leftResult->ToExpression(),
            rightResult->ToExpression()
        );
        return;
    } else {
        throw std::runtime_error("Unknown binary operator");
    }

    tos_value_ = new IRT::ExpressionWrapper(
        new IRT::BinopExpression(
            IROperator,
            leftResult->ToExpression(),
            rightResult->ToExpression()
        )
    );
}

void IrtreeBuildVisitor::Visit(InverseExpression* inverseExpression) {
    auto wrapper = Accept(inverseExpression->expr_);

    tos_value_ = new IRT::NegateConditionalWrapper(
            wrapper
    );
}

void IrtreeBuildVisitor::Visit(MethodInvocationExpression* methodInvocationExpression) {
    methodInvocationExpression->methodInvocation_->Accept(this);
}

void IrtreeBuildVisitor::Visit(ObjectMakeExpression* objectMakeExpression) {
    auto malloc_expression = new IRT::NameExpression(IRT::Label("malloc"));
    auto size = GetClassOrThrow(tree_->GetType(objectMakeExpression->typeIdentifier_))->GetVariables().size();

    auto expr_list = new IRT::ExpressionList();
    expr_list->Add(new IRT::ConstExpression(size));

    tos_value_ = new IRT::ExpressionWrapper(
            new IRT::CallExpression(malloc_expression, expr_list)
            );

    /**auto address = current_frame_->GetAddress(simpleExpression->value_);

    objectMakeExpression->
    tos_value_ = new IRT::StatementWrapper(
        new IRT::CallExpression(Expression *expression, ExpressionList *args),

    );**/
}

void IrtreeBuildVisitor::Visit(NumberExpression* numberExpression) {
    tos_value_ = new IRT::ExpressionWrapper(
            new IRT::ConstExpression(numberExpression->value_)
    );
}

void IrtreeBuildVisitor::Visit(SimpleExpression* simpleExpression) {
    auto address = current_frame_->GetAddress(simpleExpression->value_);

    tos_value_ = new IRT::ExpressionWrapper(address->ToExpression());
}

void IrtreeBuildVisitor::Visit(LengthExpression* lengthExpression) {
    // pass
}

void IrtreeBuildVisitor::Visit(AssertStatement* statement) {
    // pass
}

void IrtreeBuildVisitor::Visit(IfElseStatement* statement) {
    auto if_cond_expression = Accept(statement->expr_);

    auto true_stmt = Accept(statement->if_statement_);
    auto false_stmt = Accept(statement->else_statement_);

    IRT::Label label_true;
    IRT::Label label_false;
    IRT::Label label_join;

    IRT::Statement* suffix = new IRT::LabelStatement(label_join);

    IRT::Label* result_true = &label_join;
    IRT::Label* result_false = &label_join;

    if (false_stmt) {
        result_false = &label_false;
        suffix = new IRT::SeqStatement(
                new IRT::LabelStatement(label_false),
                new IRT::SeqStatement(false_stmt->ToStatement(), suffix)
        );

        if (true_stmt) {
            suffix = new IRT::SeqStatement(
                    new IRT::JumpStatement(label_join),
                    suffix
            );
        }
    }

    if (true_stmt) {
        result_true = &label_true;
        suffix = new IRT::SeqStatement(
                new IRT::LabelStatement(label_true),
                new IRT::SeqStatement(true_stmt->ToStatement(), suffix)
        );
    }

    tos_value_ = new IRT::StatementWrapper(
            new IRT::SeqStatement(
                    if_cond_expression->ToConditional(*result_true, *result_false),
                    suffix
            )
    );
}

void IrtreeBuildVisitor::Visit(IfStatement* statement) {
    auto if_cond_expression = Accept(statement->expr_);
    auto true_stmt = Accept(statement->statement_);

    IRT::Label label_true;
    IRT::Label label_false;
    IRT::Label label_join;

    IRT::Statement* suffix = new IRT::LabelStatement(label_join);

    IRT::Label* result_true = &label_join;
    IRT::Label* result_false = &label_join;

    if (true_stmt) {
        result_true = &label_true;
        suffix = new IRT::SeqStatement(
                new IRT::LabelStatement(label_true),
                new IRT::SeqStatement(true_stmt->ToStatement(), suffix)
        );
    }

    tos_value_ = new IRT::StatementWrapper(
            new IRT::SeqStatement(
                    if_cond_expression->ToConditional(*result_true, *result_false),
                    suffix
            )
    );
}

void IrtreeBuildVisitor::Visit(LocalVariableDeclarationStatement* statement) {
    statement->variableDeclaration_->Accept(this);
}

void IrtreeBuildVisitor::Visit(MethodInvocationStatement* statement) {
    statement->methodInvocation_->Accept(this);
}

void IrtreeBuildVisitor::Visit(PrintlnStatement* statement) {
    // TODO: add print
    tos_value_ = nullptr;
}

void IrtreeBuildVisitor::Visit(ReturnStatement* statement) {
    auto return_expr = Accept(statement->expr_);
    tos_value_ = new IRT::StatementWrapper(
    new IRT::MoveStatement(
            current_frame_->GetReturnValueAddress()->ToExpression(),
            return_expr->ToExpression()
        )
    );
}

void IrtreeBuildVisitor::Visit(ScopeStatements* statement) {
    current_frame_->SetupScope();

    if (statement->statements_.empty()) {
        tos_value_ = nullptr;
        return;
    }

    if (statement->statements_.size() == 1) {
        tos_value_ = Accept(statement->statements_[0]);
    } else {
        std::vector<IRT::Statement*> statements;
        statements.reserve(statement->statements_.size());

        for (auto subStatement: statement->statements_) {
            auto stmt = Accept(subStatement);
            if (stmt) {
                statements.push_back(stmt->ToStatement());
            }
        }
        IRT::Statement* suffix = statements.back();

        for (int index = static_cast<int>(statements.size()) - 2; index >= 0; --index) {
            suffix = new IRT::SeqStatement(
                statements.at(index),
                suffix
            );
        }
        tos_value_ = new IRT::StatementWrapper(suffix);
    }

    current_frame_->TearDownScope();
}

void IrtreeBuildVisitor::Visit(SetLvalueStatement* statement) {
    auto var_expression = current_frame_->GetAddress(
            statement->lvalue_
    )->ToExpression();
    auto rvalue = Accept(statement->expr_);

    tos_value_ = new IRT::StatementWrapper(new IRT::MoveStatement(
            var_expression,
            rvalue->ToExpression())
    );
}

void IrtreeBuildVisitor::Visit(WhileStatement* statement) {
    auto if_cond_expression = Accept(statement->expr_);
    auto true_stmt = Accept(statement->statement_);

    IRT::Label label_true;
    IRT::Label label_false;
    IRT::Label label_join;

    IRT::Statement* suffix = new IRT::LabelStatement(label_join);

    IRT::Label* result_true = &label_join;
    IRT::Label* result_false = &label_join;

    IRT::Label while_label;

    if (true_stmt) {
        result_true = &label_true;
        suffix = new IRT::SeqStatement(
                new IRT::LabelStatement(label_true),
                new IRT::SeqStatement(
                    new IRT::SeqStatement(true_stmt->ToStatement(), suffix),
                    new IRT::JumpStatement(while_label)
                )
        );
    }

    tos_value_ = new IRT::StatementWrapper(
            new IRT::SeqStatement(
                new IRT::LabelStatement(while_label),
                new IRT::SeqStatement(
                        if_cond_expression->ToConditional(*result_true, *result_false),
                        suffix
                )
            )
    );
}

IrtreeBuildVisitor::IrtreeBuildVisitor(ScopeLayerTree *layer_tree): tree_(layer_tree), current_frame_(nullptr) {
}

IrtMapping IrtreeBuildVisitor::GetTrees() {
    return method_trees_;
}

///////////////////////////
