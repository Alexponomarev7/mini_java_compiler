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

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_SIMPLE_EXPRESSION_H
