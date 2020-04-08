#ifndef COMPILER_ARRAY_MAKE_EXPRESSION_H
#define COMPILER_ARRAY_MAKE_EXPRESSION_H

#include "expression.h"

class ArrayMakeExpression : public Expression {
public:
    ArrayMakeExpression(SimpleType simpleType, Expression* sizeExpr) :
        simpleType_(simpleType)
        , sizeExpr_(sizeExpr)
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    SimpleType simpleType_;
    Expression* sizeExpr_;

    friend class PrintVisitor;
};

#endif //COMPILER_ARRAY_MAKE_EXPRESSION_H
