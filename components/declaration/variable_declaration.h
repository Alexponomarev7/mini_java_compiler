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
        visitor->Visit(this);
    }

private:
    Type type_;
    Identifier id_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
};


#endif //COMPILER_VARIABLE_DECLARATION_H
