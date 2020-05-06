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
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Expression* expr_;
    Statement* if_statement_;
    Statement* else_statement_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_IF_ELSE_STATEMENT_H
