#ifndef COMPILER_BINARY_OPERATOR_TYPE_H
#define COMPILER_BINARY_OPERATOR_TYPE_H

#include <string>

namespace IRT {
    enum class BinaryOperatorType : char {
        PLUS,
        MINUS,
        MUL,
        DIV,
        AND,
        MOD,
        OR
    };

    std::string ToString(BinaryOperatorType type);

    std::string OperatorAsm(BinaryOperatorType type);
}


#endif //COMPILER_BINARY_OPERATOR_TYPE_H
