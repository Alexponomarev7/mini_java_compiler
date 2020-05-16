#ifndef COMPILER_OR_CONDITIONAL_WRAPPER_H
#define COMPILER_OR_CONDITIONAL_WRAPPER_H

#include "conditional_wrapper.h"

namespace IRT {
    class OrConditionalWrapper: public ConditionalWrapper {
    public:
        OrConditionalWrapper(SubtreeWrapper *first, SubtreeWrapper *second);
        Statement *ToConditional(Label true_label, Label false_label) override;

        SubtreeWrapper* first_;
        SubtreeWrapper* second_;
    };

}

#endif //COMPILER_OR_CONDITIONAL_WRAPPER_H
