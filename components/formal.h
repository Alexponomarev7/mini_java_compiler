#ifndef COMPILER_FORMAL_H
#define COMPILER_FORMAL_H

#include "base.h"

class Formal : public BaseElement {
public:
    Formal(Type type, Identifier id) :
        type_(type)
        , id_(id)
    {}

    void Accept(Visitor* visitor) override {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Type type_;
    Identifier id_;

    friend class PrintVisitor;
    friend class SymbolTreeVisitor;
    friend class ScopeLayer;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_FORMAL_H
