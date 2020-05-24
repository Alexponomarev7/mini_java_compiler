//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#ifndef COMPILER_LOGIC_OPERATOR_TYPE_H
#define COMPILER_LOGIC_OPERATOR_TYPE_H

#include <string>

namespace IRT {
    enum class LogicOperatorType : char {
        LT,
        GT,
        EQ,
        NE
    };

    std::string ToString(LogicOperatorType type);

    std::string SuffixAsm(LogicOperatorType type);
}

#endif //COMPILER_LOGIC_OPERATOR_TYPE_H
