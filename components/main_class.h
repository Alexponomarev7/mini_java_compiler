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
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Identifier id_;
    std::vector<Statement*> statements_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_MAIN_CLASS_H
