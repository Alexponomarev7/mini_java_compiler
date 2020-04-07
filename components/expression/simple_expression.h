#ifndef COMPILER_SIMPLE_EXPRESSION_H
#define COMPILER_SIMPLE_EXPRESSION_H

#include "expression.h"

class SimpleExpression : public Expression {
public:
    SimpleExpression(std::string value) :
        value_(std::move(value))
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    std::string value_;
};

#endif //COMPILER_SIMPLE_EXPRESSION_H
