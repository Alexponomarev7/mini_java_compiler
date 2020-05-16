//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#include "eseq_expression.h"

IRT::EseqExpression::EseqExpression(IRT::Statement *statement, IRT::Expression *expression):
        statement_(statement), expression_(expression) {

}
void IRT::EseqExpression::Accept(IRT::Visitor *visitor) {
    visitor->Visit(this);

}
