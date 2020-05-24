#include "binary_operator_type.h"


std::string IRT::ToString(BinaryOperatorType type) {
    switch (type) {
        case BinaryOperatorType::PLUS:
            return "PLUS";
        case BinaryOperatorType::MINUS:
            return "MINUS";
        case BinaryOperatorType::MUL:
            return "MUL";
        case BinaryOperatorType::DIV:
            return "DIV";
        case BinaryOperatorType::AND:
            return "AND";
        case BinaryOperatorType::OR:
            return "OR";
    }
}

std::string IRT::OperatorAsm(BinaryOperatorType type) {
    switch (type) {
        case BinaryOperatorType::PLUS:
            return "add";
        case BinaryOperatorType::MINUS:
            return "sub";
        case BinaryOperatorType::MUL:
            return "mul";
        case BinaryOperatorType::DIV:
            return "div";
        case BinaryOperatorType::AND:
            assert(false);
        case BinaryOperatorType::OR:
            assert(false);
    }
}

