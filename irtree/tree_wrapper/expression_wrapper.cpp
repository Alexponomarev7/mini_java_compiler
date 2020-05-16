#include "expression_wrapper.h"

#include "../nodes/statements/exp_statement.h"
#include "../nodes/statements/jump_conditional_statement.h"
#include "../nodes/expressions/const_expression.h"

IRT::Expression *IRT::ExpressionWrapper::ToExpression() {
    return expression_;
}

IRT::Statement *IRT::ExpressionWrapper::ToStatement() {
    return new ExpStatement(expression_);
}

IRT::Statement *IRT::ExpressionWrapper::ToConditional(IRT::Label true_label, IRT::Label false_label) {
    return new JumpConditionalStatement(
            LogicOperatorType::NE,
            expression_,
            new ConstExpression(0),
            true_label,
            false_label
    );
}

IRT::ExpressionWrapper::ExpressionWrapper(IRT::Expression *expression): expression_(expression) {

}
