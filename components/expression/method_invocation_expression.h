#ifndef COMPILER_METHOD_INVOCATION_EXPRESSION_H
#define COMPILER_METHOD_INVOCATION_EXPRESSION_H

#include "expression.h"

class MethodInvocationExpression : public Expression {
public:
    MethodInvocationExpression(MethodInvocation* methodInvocation) :
        methodInvocation_(methodInvocation)
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    MethodInvocation* methodInvocation_;

    friend class PrintVisitor;
};

#endif //COMPILER_METHOD_INVOCATION_EXPRESSION_H
