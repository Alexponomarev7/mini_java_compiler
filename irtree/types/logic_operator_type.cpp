#include "logic_operator_type.h"

std::string IRT::ToString(IRT::LogicOperatorType type) {
    switch (type) {
        case LogicOperatorType::EQ:
            return "EQ";
        case LogicOperatorType::NE:
            return "NE";
        case LogicOperatorType::LT:
            return "LT";
        case LogicOperatorType::GT:
            return "GT";
    }
}

std::string IRT::SuffixAsm(IRT::LogicOperatorType type) {
    switch (type) {
        case LogicOperatorType::EQ:
            return "e";
        case LogicOperatorType::NE:
            return "ne";
        case LogicOperatorType::LT:
            return "le";
        case LogicOperatorType::GT:
            return "ge";
    }
}