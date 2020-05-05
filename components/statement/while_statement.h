#ifndef COMPILER_WHILE_STATEMENT_H
#define COMPILER_WHILE_STATEMENT_H

#include "statement.h"

class WhileStatement : public Statement {
public:
    WhileStatement(Expression* expr, Statement* statement) :
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
    friend class FunctionCallVisitor;
};

#endif //COMPILER_WHILE_STATEMENT_H
