//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#ifndef COMPILER_TEMP_EXPRESSION_H
#define COMPILER_TEMP_EXPRESSION_H


#include "irtree/nodes/expressions/expression.h"
#include "irtree/generators/temporary.h"

namespace IRT {
    class TempExpression : public Expression {
    public:
        explicit TempExpression(const IRT::Temporary &temporary);
        void Accept(Visitor *visitor) override;
        Temporary temporary_;
    };

}


#endif //COMPILER_TEMP_EXPRESSION_H
