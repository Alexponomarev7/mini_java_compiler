#ifndef COMPILER_RETURN_STATEMENT_H
#define COMPILER_RETURN_STATEMENT_H

#include "statement.h"

class ReturnStatement : public Statement {
public:
    ReturnStatement(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    Expression* expr_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_RETURN_STATEMENT_H
