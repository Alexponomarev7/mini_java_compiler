#ifndef COMPILER_VARIABLE_DECLARATION_H
#define COMPILER_VARIABLE_DECLARATION_H

#include "declaration.h"

class VariableDeclaration : public Declaration {
public:
    VariableDeclaration(Type type, Identifier id) :
        type_(std::move(type)),
        id_(std::move(id))
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
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
    friend class IrtreeBuildVisitor;
};


#endif //COMPILER_VARIABLE_DECLARATION_H
