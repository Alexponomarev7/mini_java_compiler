#ifndef COMPILER_NUMBER_EXPRESSION_H
#define COMPILER_NUMBER_EXPRESSION_H

#include "expression.h"

class NumberExpression : public Expression {
public:
    NumberExpression(int value) :
            value_(std::move(value))
    {}

    void Accept(Visitor* visitor) {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    int value_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class FunctionCallVisitor;
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_NUMBER_EXPRESSION_H
