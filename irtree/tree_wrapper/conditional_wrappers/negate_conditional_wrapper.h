#ifndef COMPILER_NEGATE_CONDITIONAL_WRAPPER_H
#define COMPILER_NEGATE_CONDITIONAL_WRAPPER_H

#include "conditional_wrapper.h"

namespace IRT {
    class NegateConditionalWrapper : public ConditionalWrapper {
    public:
        explicit NegateConditionalWrapper(SubtreeWrapper* wrapper);
        Statement *ToConditional(Label true_label, Label false_label) override;
    private:
        SubtreeWrapper* wrapper_;
    };

}

#endif //COMPILER_NEGATE_CONDITIONAL_WRAPPER_H
