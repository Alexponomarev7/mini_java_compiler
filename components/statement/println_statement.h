#ifndef COMPILER_PRINTLNSTATEMENT_H
#define COMPILER_PRINTLNSTATEMENT_H

#include "statement.h"

class PrintlnStatement : public Statement {
public:
    PrintlnStatement(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) override {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Expression* expr_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_PRINTLNSTATEMENT_H
