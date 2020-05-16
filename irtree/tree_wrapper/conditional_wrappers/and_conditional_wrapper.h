#ifndef COMPILER_AND_CONDITIONAL_WRAPPER_H
#define COMPILER_AND_CONDITIONAL_WRAPPER_H

#include "conditional_wrapper.h"

namespace IRT {

    class AndConditionalWrapper : public ConditionalWrapper {
    public:
        AndConditionalWrapper(SubtreeWrapper* first, SubtreeWrapper* second);
        Statement *ToConditional(Label true_label, Label false_label) override;
    private:
        SubtreeWrapper* first_;
        SubtreeWrapper* second_;
    };

}

#endif //COMPILER_AND_CONDITIONAL_WRAPPER_H
