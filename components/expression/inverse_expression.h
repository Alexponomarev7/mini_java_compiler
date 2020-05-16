#ifndef COMPILER_INVERSE_EXPRESSION_H
#define COMPILER_INVERSE_EXPRESSION_H

#include "expression.h"

class InverseExpression : public Expression {
public:
    InverseExpression(Expression* expr) :
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
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_INVERSE_EXPRESSION_H
