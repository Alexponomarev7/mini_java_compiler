#ifndef COMPILER_VISITOR_STRUCT_H
#define COMPILER_VISITOR_STRUCT_H

#include "../nodes/expressions/expression.h"
#include "../nodes/statements/statement.h"

namespace IRT {

    struct IrtStorage {
        Expression* expression_ = nullptr;
        Statement* statement_ = nullptr;
        ExpressionList* expression_list_ = nullptr;
    };
}

#endif //COMPILER_VISITOR_STRUCT_H
