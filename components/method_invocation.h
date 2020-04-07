#ifndef COMPILER_METHOD_INVOCATION_H
#define COMPILER_METHOD_INVOCATION_H

#include "base.h"

class MethodInvocation : public BaseElement {
public:
    MethodInvocation(Expression* expr, Identifier id) :
        expr_(expr)
        , id_(std::move(id))
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    Expression* expr_;
    Identifier id_;
};

#endif //COMPILER_METHOD_INVOCATION_H
