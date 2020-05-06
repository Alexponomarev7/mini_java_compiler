#ifndef COMPILER_LENGTH_EXPRESSION_H
#define COMPILER_LENGTH_EXPRESSION_H

#include "expression.h"

class LengthExpression : public Expression {
public:
    LengthExpression(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) {
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

#endif //COMPILER_LENGTH_EXPRESSION_H
