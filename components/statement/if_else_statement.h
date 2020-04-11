#ifndef COMPILER_IF_ELSE_STATEMENT_H
#define COMPILER_IF_ELSE_STATEMENT_H

#include "statement.h"

class IfElseStatement : public Statement {
public:
    IfElseStatement(Expression* expr, Statement* if_statement, Statement* else_statement) :
        expr_(expr)
        , if_statement_(if_statement)
        , else_statement_(else_statement)
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    Expression* expr_;
    Statement* if_statement_;
    Statement* else_statement_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_IF_ELSE_STATEMENT_H
