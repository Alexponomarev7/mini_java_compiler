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
    current_layer_->DeclareVariable(Symbol("true"), "bool");
    current_layer_->DeclareVariable(Symbol("false"), "bool");

    program->main_->Accept(this);
    for (const auto& classObj : program->classes_) {
        classObj->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(MainClass* mainClass) {
    auto scopeLayer = CreateScopeLayer(this);

    for (const auto& statement : mainClass->statements_) {
        statement->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(Class* classObj) {
    //auto scopeLayer = CreateScopeLayer(this);

    //current_layer_->DeclareVariable()
    //classObj->declarations_
    //classObj-> Accept(this);
}

void SymbolTreeVisitor::Visit(Formal* formal) {
    // pass
}

void SymbolTreeVisitor::Visit(MethodInvocation* methodInvocation) {
    // pass
};

void SymbolTreeVisitor::Visit(VariableDeclaration* variableDeclaration) {
    auto type = variableDeclaration->type_;
    auto variable = variableDeclaration->id_;

    current_layer_->DeclareVariable(Symbol(variable), Type(type));
};

void SymbolTreeVisitor::Visit(MethodDeclaration* methodDeclaration) {
    /**auto type = methodDeclaration->type_;
    auto id = methodDeclaration->id_;
    auto formals = methodDeclaration->formals_;

    current_layer_->DeclareMethod(Type(type), Symbol(id), formals);

    auto scopeLayer = CreateScopeLayer(this);
    for (const auto& subStatement : methodDeclaration->statements_) {
        subStatement->Accept(this);
    }**/
};

void SymbolTreeVisitor::Visit(ArrayMakeExpression* expression) {
    // pass
}

void SymbolTreeVisitor::Visit(BinaryExpression* binaryExpression) {
    // pass
}

void SymbolTreeVisitor::Visit(InverseExpression* expression) {
    // pass
}

void SymbolTreeVisitor::Visit(MethodInvocationExpression* expression) {
    // pass
}

void SymbolTreeVisitor::Visit(ObjectMakeExpression* expression) {
    // pass
}

void SymbolTreeVisitor::Visit(SimpleExpression* expression) {
    // pass
}

void SymbolTreeVisitor::Visit(NumberExpression *expression) {
    // pass
}

void SymbolTreeVisitor::Visit(LengthExpression* expression) {
    // pass
}

void SymbolTreeVisitor::Visit(AssertStatement* statement) {
    // pass
}

void SymbolTreeVisitor::Visit(IfElseStatement* statement) {
    statement->if_statement_->Accept(this);
    statement->else_statement_->Accept(this);
}

void SymbolTreeVisitor::Visit(IfStatement* statement) {
    statement->statement_->Accept(this);
}

void SymbolTreeVisitor::Visit(LocalVariableDeclarationStatement* statement) {
    statement->variableDeclaration_->Accept(this);
}

void SymbolTreeVisitor::Visit(MethodInvocationStatement* statement) {
    // pass
}

void SymbolTreeVisitor::Visit(PrintlnStatement* statement) {
    // pass
}

void SymbolTreeVisitor::Visit(ReturnStatement* statement) {
    // pass
}

void SymbolTreeVisitor::Visit(ScopeStatements* statement) {
    auto scopeLayer = CreateScopeLayer(this);

    for (const auto& curStatement : statement->statements_) {
        curStatement->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(SetLvalueStatement* statement) {
    // pass
}

void SymbolTreeVisitor::Visit(WhileStatement* statement) {
    statement->statement_->Accept(this);
}

ScopeLayer* SymbolTreeVisitor::GetRoot() {
    return current_layer_;
}
