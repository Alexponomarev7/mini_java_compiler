#ifndef COMPILER_CONDITIONAL_WRAPPER_H
#define COMPILER_CONDITIONAL_WRAPPER_H

#include "../subtree_wrapper.h"

namespace IRT {

    class ConditionalWrapper : public SubtreeWrapper {
    public:
        virtual ~ConditionalWrapper() = default;
        Expression *ToExpression() override;
        Statement *ToStatement() override;

    };

}

#endif //COMPILER_CONDITIONAL_WRAPPER_H
