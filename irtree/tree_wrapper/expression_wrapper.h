#ifndef COMPILER_EXPRESSION_WRAPPER_H
#define COMPILER_EXPRESSION_WRAPPER_H


#include "subtree_wrapper.h"
#include "../nodes/statements/statement.h"

namespace IRT {

    class ExpressionWrapper : public SubtreeWrapper {
    public:

        explicit ExpressionWrapper(Expression* expression);
        virtual ~ExpressionWrapper() = default;
        Expression *ToExpression() override;
        Statement *ToStatement() override;
        Statement *ToConditional(Label true_label, Label false_label) override;
    private:
        Expression* expression_;
    };

}

#endif //COMPILER_EXPRESSION_WRAPPER_H
