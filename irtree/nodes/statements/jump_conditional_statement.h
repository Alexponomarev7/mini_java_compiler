#ifndef COMPILER_JUMP_CONDITIONAL_STATEMENT_H
#define COMPILER_JUMP_CONDITIONAL_STATEMENT_H

#include "statement.h"
#include "irtree/types/logic_operator_type.h"
#include "irtree/nodes/expressions/expression.h"
#include "irtree/generators/label.h"

namespace IRT {
    class JumpConditionalStatement : public Statement {
    public:
        JumpConditionalStatement(
                LogicOperatorType type,
                Expression* left,
                Expression* right,
                Label label_true,
                Label label_false
        );
        void Accept(Visitor *visitor) override;
        LogicOperatorType operator_type_;
        Label label_true_;
        Label label_false_;
        Expression* left_operand_;
        Expression* right_operand_;

    };

}

#endif //COMPILER_JUMP_CONDITIONAL_STATEMENT_H
