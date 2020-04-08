#ifndef COMPILER_INVERSE_EXPRESSION_H
#define COMPILER_INVERSE_EXPRESSION_H

#include "expression.h"

class InverseExpression : public Expression {
public:
    InverseExpression(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    Expression* expr_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
};

#endif //COMPILER_INVERSE_EXPRESSION_H
