#ifndef COMPILER_METHOD_INVOCATION_STATEMENT_H
#define COMPILER_METHOD_INVOCATION_STATEMENT_H

#include "statement.h"

class MethodInvocationStatement : public Statement {
public:
    MethodInvocationStatement(MethodInvocation* methodInvocation) :
        methodInvocation_(methodInvocation)
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    MethodInvocation* methodInvocation_;

    friend class PrintVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_METHOD_INVOCATION_STATEMENT_H
