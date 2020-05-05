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
        visitor->Visit(this);
    }

private:
    Type type_;
    Identifier id_;

    friend class PrintVisitor;
    friend class SymbolTreeVisitor;
    friend class ScopeLayer;
};

#endif //COMPILER_FORMAL_H
