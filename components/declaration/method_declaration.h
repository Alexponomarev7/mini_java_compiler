#ifndef COMPILER_METHOD_DECLARATION_H
#define COMPILER_METHOD_DECLARATION_H

#include "declaration.h"

class MethodDeclaration : public Declaration {
public:
    MethodDeclaration(Type type, Identifier id, std::vector<Formal*> formals, std::vector<Statement*> statements) :
        type_(std::move(type)),
        id_(std::move(id)),
        formals_(std::move(formals)),
        statements_(std::move(statements))
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
    std::vector<Formal*> formals_;
    std::vector<Statement*> statements_;

    friend class PrintVisitor;
    friend class SymbolTreeVisitor;
    friend class ScopeLayer;
    friend class FunctionCallVisitor;
    friend class FrameEmulator;
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_METHOD_DECLARATION_H
