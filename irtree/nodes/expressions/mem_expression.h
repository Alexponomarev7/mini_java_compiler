//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#ifndef COMPILER_MEM_EXPRESSION_H
#define COMPILER_MEM_EXPRESSION_H

#include "expression.h"

namespace IRT {

    class MemExpression : public Expression {
    public:
        MemExpression(Expression *expression);
        void Accept(Visitor *visitor) override;
        Expression* expression_;
    };

}

#endif //COMPILER_MEM_EXPRESSION_H
