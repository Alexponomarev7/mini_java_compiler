#ifndef COMPILER_SCOPESTATEMENTS_H
#define COMPILER_SCOPESTATEMENTS_H

#include "statement.h"

class ScopeStatements : public Statement {
public:
    ScopeStatements(std::vector<Statement*> statements) :
        statements_(std::move(statements))
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    std::vector<Statement*> statements_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_SCOPESTATEMENTS_H
