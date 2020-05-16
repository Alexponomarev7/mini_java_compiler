#include "and_conditional_wrapper.h"

#include "../../nodes/statements/seq_statement.h"
#include "../../nodes/statements/label_statement.h"

namespace IRT {

    Statement *AndConditionalWrapper::ToConditional(Label true_label, Label false_label) {
        Label middle_label;

        return new SeqStatement(
                first_->ToConditional(middle_label, false_label),
                new SeqStatement(
                        new LabelStatement(middle_label),
                        second_->ToConditional(true_label, false_label)
                )
        );
    }
    AndConditionalWrapper::AndConditionalWrapper(SubtreeWrapper *first, SubtreeWrapper *second): first_(first), second_(second) {

    }
}
