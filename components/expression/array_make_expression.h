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
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    SimpleType simpleType_;
    Expression* sizeExpr_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_ARRAY_MAKE_EXPRESSION_H
