#include "negate_conditional_wrapper.h"

namespace IRT {

    Statement *NegateConditionalWrapper::ToConditional(Label true_label, Label false_label) {
        return wrapper_->ToConditional(false_label, true_label);
    }

    NegateConditionalWrapper::NegateConditionalWrapper(SubtreeWrapper *wrapper): wrapper_(wrapper) {

    }
}
