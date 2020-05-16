#ifndef COMPILER_SUBTREE_WRAPPER_H
#define COMPILER_SUBTREE_WRAPPER_H

#include "../generators/label.h"
#include "../nodes/expressions/expression.h"
#include "../nodes/statements/statement.h"

namespace IRT {
    class SubtreeWrapper {
    public:
        virtual ~SubtreeWrapper() = default;
        virtual Expression* ToExpression() = 0;
        virtual Statement* ToStatement() = 0;
        virtual Statement* ToConditional(Label true_label, Label false_label) = 0;
    };

}

#endif //COMPILER_SUBTREE_WRAPPER_H
