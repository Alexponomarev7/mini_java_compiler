//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#include "or_conditional_wrapper.h"

#include "../../nodes/statements/label_statement.h"
#include "../../nodes/statements/seq_statement.h"

namespace IRT {

    Statement *OrConditionalWrapper::ToConditional(Label true_label, Label false_label) {
        Label middle_label;
        return new SeqStatement(
                first_->ToConditional(true_label, middle_label),
                new SeqStatement(
                        new LabelStatement(middle_label),
                        second_->ToConditional(true_label, false_label)
                )
        );
    }
    OrConditionalWrapper::OrConditionalWrapper(SubtreeWrapper *first, SubtreeWrapper *second): first_(first), second_(second) {

    }
}
