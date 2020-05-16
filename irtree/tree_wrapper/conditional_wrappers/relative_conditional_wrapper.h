//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#ifndef COMPILER_RELATIVE_CONDITIONAL_WRAPPER_H
#define COMPILER_RELATIVE_CONDITIONAL_WRAPPER_H


#include "conditional_wrapper.h"
#include "../../types/logic_operator_type.h"


namespace IRT {
    class RelativeConditionalWrapper: public ConditionalWrapper {
    public:
        RelativeConditionalWrapper(LogicOperatorType type, Expression *lhs, Expression *rhs);
        Statement *ToConditional(Label true_label, Label false_label) override;

        Expression* lhs_;
        Expression* rhs_;
        LogicOperatorType operator_type_;

    };

}

#endif //COMPILER_RELATIVE_CONDITIONAL_WRAPPER_H
