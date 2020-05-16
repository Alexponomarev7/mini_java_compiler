#ifndef COMPILER_METHOD_INVOCATION_EXPRESSION_H
#define COMPILER_METHOD_INVOCATION_EXPRESSION_H

#include "expression.h"

class MethodInvocationExpression : public Expression {
public:
    MethodInvocationExpression(MethodInvocation* methodInvocation) :
        methodInvocation_(methodInvocation)
    {}

    void Accept(Visitor* visitor) {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    MethodInvocation* methodInvocation_;

    friend class PrintVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_METHOD_INVOCATION_EXPRESSION_H
