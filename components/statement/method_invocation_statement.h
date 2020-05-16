#ifndef COMPILER_METHOD_INVOCATION_STATEMENT_H
#define COMPILER_METHOD_INVOCATION_STATEMENT_H

#include "statement.h"

class MethodInvocationStatement : public Statement {
public:
    MethodInvocationStatement(MethodInvocation* methodInvocation) :
        methodInvocation_(methodInvocation)
    {}

    void Accept(Visitor* visitor) override {
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

#endif //COMPILER_METHOD_INVOCATION_STATEMENT_H
