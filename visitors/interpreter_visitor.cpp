#include <components/program.h>
#include "interpreter_visitor.h"

InterpreterVisitor::InterpreterVisitor(ScopeLayer* root) : current_layer_(root)
{
    current_layer_->Put(Symbol("true"), std::make_shared<Boolean>(true));
    current_layer_->Put(Symbol("false"), std::make_shared<Boolean>(false));

    offsets_.push(0);
}

void InterpreterVisitor::Visit(Program* program) {
    for (const auto& classObj : program->classes_) {
        classObj->Accept(this);
    }

    program->main_->Accept(this);
}

void InterpreterVisitor::Visit(MainClass* mainClass) {
    current_layer_ = current_layer_->GetChild(offsets_.top());
    offsets_.push(0);

    for (const auto& statement : mainClass->statements_) {
        statement->Accept(this);
    }

    offsets_.pop();
    size_t index = offsets_.top();
    offsets_.pop();
    offsets_.push(index + 1);
    current_layer_ = current_layer_->GetParent();
}

void InterpreterVisitor::Visit(Class* classObj) {
    // pass
    current_layer_ = current_layer_->GetChild(offsets_.top());
    offsets_.push(0);

    offsets_.pop();
    size_t index = offsets_.top();
    offsets_.pop();
    offsets_.push(index + 1);
    current_layer_ = current_layer_->GetParent();
}

void InterpreterVisitor::Visit(Formal* formal) {
    // pass
}

void InterpreterVisitor::Visit(MethodInvocation* methodInvocation) {
    // pass
}

void InterpreterVisitor::Visit(VariableDeclaration* variableDeclaration) {
    //std::cout << "Var decl called" << std::endl;
}

void InterpreterVisitor::Visit(MethodDeclaration* methodDeclaration) {
    // pass
}

void InterpreterVisitor::Visit(ArrayMakeExpression* arrayMakeExpression) {
    auto length = GetIntOrThrow(Accept(arrayMakeExpression->sizeExpr_));
    auto simpleType = current_layer_->Get(arrayMakeExpression->simpleType_);
    tos_value_ = std::make_shared<Array>(simpleType, length);
    // pass
}

void InterpreterVisitor::Visit(BinaryExpression* binaryExpression) {
    auto leftResult = Accept(binaryExpression->leftExpr_);
    auto rightResult = Accept(binaryExpression->rightExpr_);

    if (binaryExpression->binaryOperator_ == "+") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) + GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "-") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) - GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "*") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) * GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "/") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) / GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "%") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) % GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "&&") {
        tos_value_ = std::make_shared<Boolean>(GetBoolOrThrow(leftResult) && GetBoolOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "||") {
        tos_value_ = std::make_shared<Boolean>(GetBoolOrThrow(leftResult) || GetBoolOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "==") {
        tos_value_ = std::make_shared<Boolean>(GetIntOrThrow(leftResult) == GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "<") {
        tos_value_ = std::make_shared<Boolean>(GetIntOrThrow(leftResult) < GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == ">") {
        tos_value_ = std::make_shared<Boolean>(GetIntOrThrow(leftResult) > GetIntOrThrow(rightResult));
    } else {
        throw std::runtime_error("Unknown binary operator");
    }
}

void InterpreterVisitor::Visit(InverseExpression* inverseExpression) {
    auto result = GetBoolOrThrow(Accept(inverseExpression->expr_));
    tos_value_ = std::make_shared<Boolean>(!result);
}

void InterpreterVisitor::Visit(MethodInvocationExpression* methodInvocationExpression) {
    // pass
}

void InterpreterVisitor::Visit(ObjectMakeExpression* objectMakeExpression) {
    // pass
    tos_value_ = current_layer_->Get(Symbol(objectMakeExpression->typeIdentifier_));
}

void InterpreterVisitor::Visit(NumberExpression* numberExpression) {
    tos_value_ = std::make_shared<Integer>(numberExpression->value_);
}

void InterpreterVisitor::Visit(SimpleExpression* simpleExpression) {
    tos_value_ = current_layer_->Get(Symbol(simpleExpression->value_));
}

void InterpreterVisitor::Visit(LengthExpression* lengthExpression) {
    // pass
    auto array = GetArrayOrThrow(Accept(lengthExpression->expr_));
    tos_value_ = std::make_shared<Integer>(array.size());
}

void InterpreterVisitor::Visit(AssertStatement* statement) {
    auto result = Accept(statement->expr_);

    if (!GetBoolOrThrow(result)) {
        throw std::runtime_error("Assertion failed.");
    }
}

void InterpreterVisitor::Visit(IfElseStatement* statement) {
    auto result = Accept(statement->expr_);

    if (GetBoolOrThrow(result)) {
        statement->if_statement_->Accept(this);
    } else {
        statement->else_statement_->Accept(this);
    }
}

void InterpreterVisitor::Visit(IfStatement* statement) {
    auto result = Accept(statement->expr_);

    if (GetBoolOrThrow(result)) {
        statement->statement_->Accept(this);
    }
}

void InterpreterVisitor::Visit(LocalVariableDeclarationStatement* statement) {
    statement->variableDeclaration_->Accept(this);
}

void InterpreterVisitor::Visit(MethodInvocationStatement* statement) {
    // pass
}

void InterpreterVisitor::Visit(PrintlnStatement* statement) {
    auto result = GetIntOrThrow(Accept(statement->expr_));
    std::cout << result << std::endl;
}

void InterpreterVisitor::Visit(ReturnStatement* statement) {
    auto result = GetIntOrThrow(Accept(statement->expr_));
    exit(result);
}

void InterpreterVisitor::Visit(ScopeStatements* statement) {
    //std::cout << "Going inside" << std::endl;
    current_layer_ = current_layer_->GetChild(offsets_.top());
    offsets_.push(0);

    for (const auto& subStatement : statement->statements_) {
        subStatement->Accept(this);
    }

    offsets_.pop();
    size_t index = offsets_.top();
    offsets_.pop();
    offsets_.push(index + 1);
    current_layer_ = current_layer_->GetParent();
}

void InterpreterVisitor::Visit(SetLvalueStatement* statement) {
    current_layer_->Put(Symbol(statement->lvalue_), Accept(statement->expr_));
}

void InterpreterVisitor::Visit(WhileStatement* statement) {
    auto result = Accept(statement->expr_);

    while (GetBoolOrThrow(result)) {
        statement->statement_->Accept(this);
        result = Accept(statement->expr_);
    }
}
