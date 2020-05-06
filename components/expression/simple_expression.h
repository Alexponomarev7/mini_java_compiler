#ifndef COMPILER_SIMPLE_EXPRESSION_H
#define COMPILER_SIMPLE_EXPRESSION_H

#include "expression.h"

class SimpleExpression : public Expression {
public:
    SimpleExpression(std::string value) :
        value_(std::move(value))
    {}

    void Accept(Visitor* visitor) {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    std::string value_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_SIMPLE_EXPRESSION_H
