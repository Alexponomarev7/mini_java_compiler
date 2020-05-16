#ifndef COMPILER_NAME_EXPRESSION_H
#define COMPILER_NAME_EXPRESSION_H

#include "name_expression.h"

namespace IRT {

    void NameExpression::Accept(IRT::Visitor *visitor) {
        visitor->Visit(this);

    }

    NameExpression::NameExpression(Label label) : label_(label) {

    }
}


#endif //COMPILER_NAME_EXPRESSION_H
