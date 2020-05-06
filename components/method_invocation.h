#ifndef COMPILER_METHOD_INVOCATION_H
#define COMPILER_METHOD_INVOCATION_H

#include "base.h"

class MethodInvocation : public BaseElement {
public:
    MethodInvocation(Expression* expr, Identifier id, std::vector<std::string> params) :
        expr_(expr)
        , id_(std::move(id))
        , params_(std::move(params))
    {}

    void Accept(Visitor* visitor) override {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Expression* expr_;
    Identifier id_;
    std::vector<std::string> params_;

    friend class PrintVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_METHOD_INVOCATION_H
