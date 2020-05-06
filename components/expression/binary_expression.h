#ifndef COMPILER_BINARY_EXPRESSION_H
#define COMPILER_BINARY_EXPRESSION_H

#include "expression.h"

class BinaryExpression : public Expression {
public:
    BinaryExpression(Expression* leftExpr, Expression* rightExpr, BinaryOperator binaryOperator) :
        leftExpr_(leftExpr)
        , rightExpr_(rightExpr)
        , binaryOperator_(std::move(binaryOperator))
    {}

    void Accept(Visitor* visitor) {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Expression* leftExpr_;
    Expression* rightExpr_;
    BinaryOperator binaryOperator_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_BINARY_EXPRESSION_H
