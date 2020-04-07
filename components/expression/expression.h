#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#include "components/base.h"

class Expression : public BaseElement {
    virtual void Accept(Visitor* visitor) = 0;
};

using BinaryOperator = std::string;

#endif //COMPILER_EXPRESSION_H
