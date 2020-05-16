#ifndef COMPILER_BINOP_EXPRESSION_H
#define COMPILER_BINOP_EXPRESSION_H


#include "irtree/types/binary_operator_type.h"
#include "expression.h"

namespace IRT {
    class BinopExpression : public Expression {
    public:
        BinopExpression(BinaryOperatorType type,
                        Expression *first,
                        Expression *second);
        void Accept(Visitor *visitor) override;
        BinaryOperatorType operator_type_;
        Expression* first_;
        Expression* second_;
    };

}

#endif //COMPILER_BINOP_EXPRESSION_H
