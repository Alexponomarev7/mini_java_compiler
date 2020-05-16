//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#ifndef COMPILER_ESEQ_EXPRESSION_H
#define COMPILER_ESEQ_EXPRESSION_H


#include "irtree/nodes/statements/statement.h"
#include "expression.h"

namespace IRT {

    class EseqExpression: public Expression {
    public:
        EseqExpression(Statement* statement, Expression* expression);
        void Accept(Visitor *visitor) override;

        Statement* statement_;
        Expression* expression_;
    };

}

#endif //COMPILER_ESEQ_EXPRESSION_H
