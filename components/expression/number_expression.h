#ifndef COMPILER_NUMBER_EXPRESSION_H
#define COMPILER_NUMBER_EXPRESSION_H

#include "expression.h"

class NumberExpression : public Expression {
public:
    NumberExpression(int value) :
            value_(std::move(value))
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    int value_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_NUMBER_EXPRESSION_H
