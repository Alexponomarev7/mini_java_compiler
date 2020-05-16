#ifndef COMPILER_ADDRESS_H
#define COMPILER_ADDRESS_H

#include <irtree/nodes/expressions/expression.h>

namespace IRT {

    class Address {
    public:
        virtual ~Address() = default;
        virtual Expression* ToExpression() = 0;
    };

}

#endif //COMPILER_ADDRESS_H
