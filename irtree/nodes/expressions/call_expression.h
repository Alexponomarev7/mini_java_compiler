//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#ifndef COMPILER_CALL_EXPRESSION_H
#define COMPILER_CALL_EXPRESSION_H


#include "expression.h"

namespace IRT {
    class CallExpression: public Expression {
    public:
        CallExpression(Expression *expression, ExpressionList *args);
        void Accept(Visitor *visitor) override;
        Expression* function_name_;
        ExpressionList* args_;

    };
}


#endif //COMPILER_CALL_EXPRESSION_H
