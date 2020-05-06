#include "symbol_tree_visitor.h"


#include <iostream>
#include <components/program.h>

#include "types/integer.h"
#include "types/types.h"

SymbolTreeVisitor::SymbolTreeVisitor() :
    tree_(new ScopeLayer())
{
    current_layer_ = tree_.root_;
}

void SymbolTreeVisitor::Visit(Program* program) {
    tree_.AddType("int", std::make_shared<Integer>());
    tree_.AddType("bool", std::make_shared<Boolean>());

    auto trueValue = std::make_shared<Boolean>(true);
    current_layer_->DeclareVariable(Symbol("true"), trueValue);
    auto falseValue = std::make_shared<Boolean>(false);
    current_layer_->DeclareVariable(Symbol("false"), falseValue);

    for (const auto& classObj : program->classes_) {
        classObj->Accept(this);

        auto classImpl = std::make_shared<ClassType>(classObj->id_, variables_);
        tree_.AddType(classObj->id_, classImpl);

        variables_.clear();
    }

    program->main_->Accept(this);
}

void SymbolTreeVisitor::Visit(MainClass* mainClass) {
    // Main class Scope
    //auto scopeLayerMainClass = CreateScopeLayer(this);

    // main method scope
    // Declaring main method
    auto mainDeclaration = new MethodDeclaration("void", "main", {}, mainClass->statements_);
    current_layer_->DeclareFunction(Symbol(mainClass->id_), Symbol("main"), mainDeclaration);
    auto new_layer = new ScopeLayer(current_layer_);
    current_layer_ = new_layer;
    for (const auto &statement : mainClass->statements_) {
        statement->Accept(this);
    }

    tree_.AddMapping(Symbol("main"), new_layer);
    current_layer_ = current_layer_->GetParent();
    functions_[Symbol("main")] = mainDeclaration;
}

void SymbolTreeVisitor::Visit(Class* classObj) {
    auto scopeLayer = CreateScopeLayer(this);
    current_class_ = classObj;

    for (const auto& declaration : classObj->declarations_) {
        declaration->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(Formal* formal) {
    formals_.emplace_back(formal->type_, formal->id_);
}

void SymbolTreeVisitor::Visit(MethodInvocation* methodInvocation) {
    // We don't check function name because function could be created after
    methodInvocation->expr_->Accept(this);
};

void SymbolTreeVisitor::Visit(VariableDeclaration* variableDeclaration) {
    auto type = variableDeclaration->type_;
    auto variable = variableDeclaration->id_;
    variables_.emplace_back(type, variable);

    bool isArray = false;
    if (IsArrayType(type)) {
        type = GetBasicType(type);
        isArray = true;
    }

    auto typeObject = tree_.GetType(type);
    if (isArray) {
        current_layer_->DeclareVariable(Symbol(variable), std::make_shared<Array>(typeObject));
    } else {
        current_layer_->DeclareVariable(Symbol(variable), typeObject);
    }
};

void SymbolTreeVisitor::Visit(MethodDeclaration* methodDeclaration) {
    // TODO: fix this name
    auto id = "class " + current_class_->id_ + "::" + methodDeclaration->id_;
    current_layer_->DeclareFunction(Symbol(current_class_->id_), Symbol(id), methodDeclaration);

    auto new_layer = new ScopeLayer(current_layer_);
    current_layer_ = new_layer;

    // TODO delete!
    current_layer_->DeclareVariable(Symbol("this"),
            std::shared_ptr<Object>(new ClassType(current_class_->id_, {})));
    for (auto formal : methodDeclaration->formals_) {
        current_layer_->DeclareVariable(Symbol(formal->id_), tree_.GetType(formal->type_));
    }

    for (auto statement : methodDeclaration->statements_) {
        statement->Accept(this);
    }

    tree_.AddMapping(Symbol(id), new_layer);
    current_layer_ = current_layer_->GetParent();

    functions_[Symbol(id)] = methodDeclaration;
};

std::unordered_map<Symbol, MethodDeclaration*> SymbolTreeVisitor::GetFunctions() const {
    return functions_;
}

void SymbolTreeVisitor::Visit(ArrayMakeExpression* expression) {
    expression->sizeExpr_->Accept(this);
}

void SymbolTreeVisitor::Visit(BinaryExpression* binaryExpression) {
    binaryExpression->leftExpr_->Accept(this);
    binaryExpression->rightExpr_->Accept(this);
}

void SymbolTreeVisitor::Visit(InverseExpression* expression) {
    expression->expr_->Accept(this);
}

void SymbolTreeVisitor::Visit(MethodInvocationExpression* expression) {
    expression->methodInvocation_->Accept(this);
}

void SymbolTreeVisitor::Visit(ObjectMakeExpression* expression) {
    tos_value_ = tree_.GetType(expression->typeIdentifier_);
}

void SymbolTreeVisitor::Visit(SimpleExpression* expression) {
}

void SymbolTreeVisitor::Visit(NumberExpression *expression) {
}

void SymbolTreeVisitor::Visit(LengthExpression* expression) {
    expression->expr_->Accept(this);
}

void SymbolTreeVisitor::Visit(AssertStatement* statement) {
    statement->expr_->Accept(this);
}

void SymbolTreeVisitor::Visit(IfElseStatement* statement) {
    statement->expr_->Accept(this);
    statement->if_statement_->Accept(this);
    statement->else_statement_->Accept(this);
}

void SymbolTreeVisitor::Visit(IfStatement* statement) {
    statement->expr_->Accept(this);
    statement->statement_->Accept(this);
}

void SymbolTreeVisitor::Visit(LocalVariableDeclarationStatement* statement) {
    statement->variableDeclaration_->Accept(this);
}

void SymbolTreeVisitor::Visit(MethodInvocationStatement* statement) {
    statement->methodInvocation_->Accept(this);
}

void SymbolTreeVisitor::Visit(PrintlnStatement* statement) {
    statement->expr_->Accept(this);
}

void SymbolTreeVisitor::Visit(ReturnStatement* statement) {
    statement->expr_->Accept(this);
}

void SymbolTreeVisitor::Visit(ScopeStatements* statement) {
    auto scopeLayer = CreateScopeLayer(this);

    for (const auto& curStatement : statement->statements_) {
        curStatement->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(SetLvalueStatement* statement) {
    statement->expr_->Accept(this);
}

void SymbolTreeVisitor::Visit(WhileStatement* statement) {
    statement->statement_->Accept(this);
}

ScopeLayerTree SymbolTreeVisitor::GetRoot() {
    return tree_;
}
