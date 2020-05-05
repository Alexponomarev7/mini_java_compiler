#ifndef COMPILER_LENGTH_EXPRESSION_H
#define COMPILER_LENGTH_EXPRESSION_H

#include "expression.h"

class LengthExpression : public Expression {
public:
    LengthExpression(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    Expression* expr_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_LENGTH_EXPRESSION_H
