#ifndef COMPILER_VISITOR_H
#define COMPILER_VISITOR_H

#include "forward_decl.h"

class Visitor {
public:
    virtual void Visit(Program* program) = 0;

    virtual void Visit(MainClass* mainClass) = 0;
    virtual void Visit(Class* classObj) = 0;
    virtual void Visit(Formal* formal) = 0;
    virtual void Visit(MethodInvocation* methodInvocation) = 0;

    virtual void Visit(VariableDeclaration* variableDeclaration) = 0;
    virtual void Visit(MethodDeclaration* methodDeclaration) = 0;

    virtual void Visit(ArrayMakeExpression* expression) = 0;
    virtual void Visit(BinaryExpression* expression) = 0;
    virtual void Visit(InverseExpression* expression) = 0;
    virtual void Visit(MethodInvocationExpression* expression) = 0;
    virtual void Visit(ObjectMakeExpression* expression) = 0;
    virtual void Visit(SimpleExpression* expression) = 0;

    virtual void Visit(AssertStatement* statement) = 0;
    virtual void Visit(IfElseStatement* statement) = 0;
    virtual void Visit(IfStatement* statement) = 0;
    virtual void Visit(LocalVariableDeclarationStatement* statement) = 0;
    virtual void Visit(MethodInvocationStatement* statement) = 0;
    virtual void Visit(PrintlnStatement* statement) = 0;
    virtual void Visit(ReturnStatement* statement) = 0;
    virtual void Visit(ScopeStatements* statement) = 0;
    virtual void Visit(SetLvalueStatement* statement) = 0;
    virtual void Visit(WhileStatement* statement) = 0;
};

#endif //COMPILER_VISITOR_H
