#ifndef COMPILER_STATEMENT_WRAPPER_H
#define COMPILER_STATEMENT_WRAPPER_H

#include "subtree_wrapper.h"

namespace IRT {
    class StatementWrapper : public SubtreeWrapper {
    public:
        explicit StatementWrapper(Statement* statement);
        Expression *ToExpression() override;
        Statement *ToStatement() override;
        Statement *ToConditional(Label true_label, Label false_label) override;
    private:
        Statement* statement_;
    };

}

#endif //COMPILER_STATEMENT_WRAPPER_H
