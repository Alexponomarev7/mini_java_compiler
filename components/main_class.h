#ifndef COMPILER_MAIN_CLASS_H
#define COMPILER_MAIN_CLASS_H

#include "base.h"

class MainClass : public BaseElement {
public:
    MainClass(Identifier id, std::vector<Statement*> statements) :
        id_(std::move(id))
        , statements_(std::move(statements))
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    Identifier id_;
    std::vector<Statement*> statements_;

    friend PrintVisitor;
};

#endif //COMPILER_MAIN_CLASS_H
