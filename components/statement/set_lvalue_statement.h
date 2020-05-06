#ifndef COMPILER_SET_LVALUE_STATEMENT_H
#define COMPILER_SET_LVALUE_STATEMENT_H

#include "statement.h"

class SetLvalueStatement : public Statement {
public:
    SetLvalueStatement(Lvalue lvalue, Expression* expr) :
        lvalue_(lvalue)
        , expr_(expr)
    {}

    void Accept(Visitor* visitor) override {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Lvalue lvalue_;
    Expression* expr_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_SET_LVALUE_STATEMENT_H
