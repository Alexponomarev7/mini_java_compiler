#ifndef COMPILER_SCOPESTATEMENTS_H
#define COMPILER_SCOPESTATEMENTS_H

#include "statement.h"

class ScopeStatements : public Statement {
public:
    ScopeStatements(std::vector<Statement*> statements) :
        statements_(std::move(statements))
    {}

    void Accept(Visitor* visitor) override {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    std::vector<Statement*> statements_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_SCOPESTATEMENTS_H
