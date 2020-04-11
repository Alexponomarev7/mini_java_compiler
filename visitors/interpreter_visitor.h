#ifndef COMPILER_INTERPRETER_H
#define COMPILER_INTERPRETER_H

#include "template_visitor.h"
#include "visitors/symbol_tree_visitor.h"

#include <map>
#include <exception>
#include <iostream>
#include <vector>
#include <cassert>

#include "types/types.h"

class InterpreterVisitor : public TemplateVisitor<std::shared_ptr<Object>> {
public:
    InterpreterVisitor(ScopeLayer* root);

    void Visit(Program* program) override;

    void Visit(MainClass* mainClass) override;
    void Visit(Class* classObj) override;
    void Visit(Formal* formal) override;
    void Visit(MethodInvocation* methodInvocation) override;

    void Visit(VariableDeclaration* variableDeclaration) override;
    void Visit(MethodDeclaration* methodDeclaration) override;

    void Visit(ArrayMakeExpression* expression) override;
    void Visit(BinaryExpression* expression) override;
    void Visit(InverseExpression* expression) override;
    void Visit(MethodInvocationExpression* expression) override;
    void Visit(ObjectMakeExpression* expression) override;
    void Visit(SimpleExpression* expression) override;
    void Visit(LengthExpression* expression) override;
    void Visit(NumberExpression* expression) override;

    void Visit(AssertStatement* statement) override;
    void Visit(IfElseStatement* statement) override;
    void Visit(IfStatement* statement) override;
    void Visit(LocalVariableDeclarationStatement* statement) override;
    void Visit(MethodInvocationStatement* statement) override;
    void Visit(PrintlnStatement* statement) override;
    void Visit(ReturnStatement* statement) override;
    void Visit(ScopeStatements* statement) override;
    void Visit(SetLvalueStatement* statement) override;
    void Visit(WhileStatement* statement) override;

private:
    ScopeLayer* current_layer_;
    std::stack<int> offsets_;
};

#endif //COMPILER_PRINTER_H
