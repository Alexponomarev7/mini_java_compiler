#ifndef COMPILER_IF_STATEMENT_H
#define COMPILER_IF_STATEMENT_H

#include "statement.h"

class IfStatement : public Statement {
public:
    IfStatement(Expression* expr, Statement* statement) :
        expr_(expr)
        , statement_(statement)
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    Expression* expr_;
    Statement* statement_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_IF_STATEMENT_H
