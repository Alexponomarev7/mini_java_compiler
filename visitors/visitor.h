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

    virtual void Visit(Expression* expression) = 0;

    virtual void Visit(Statement* statement) = 0;
};

#endif //COMPILER_VISITOR_H
