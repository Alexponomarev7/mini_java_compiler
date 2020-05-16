#include "conditional_wrapper.h"

#include "../../generators/temporary.h"
#include "../../nodes/expressions/temp_expression.h"
#include "../../nodes/expressions/const_expression.h"
#include "../../nodes/expressions/eseq_expression.h"
#include "../../nodes/statements/seq_statement.h"
#include "../../nodes/statements/move_statement.h"
#include "../../nodes/statements/label_statement.h"

namespace IRT {
    Expression *IRT::ConditionalWrapper::ToExpression() {
        auto* temp_expression = new TempExpression(Temporary());
        Label label_true;
        Label label_false;
        return new EseqExpression(
                new SeqStatement(
                        new MoveStatement(temp_expression, new ConstExpression(1)),
                        new SeqStatement(
                                ToConditional(label_true, label_false),
                                new SeqStatement(
                                        new LabelStatement(label_false),
                                        new SeqStatement(
                                                new MoveStatement(temp_expression, new ConstExpression(0)),
                                                new LabelStatement(label_true)
                                        )
                                )
                        )
                ),
                temp_expression
        );
    }

    Statement *IRT::ConditionalWrapper::ToStatement() {
        return nullptr;
    }

}
