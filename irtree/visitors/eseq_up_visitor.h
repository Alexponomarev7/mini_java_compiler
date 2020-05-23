#ifndef COMPILER_ESEQ_UP_VISITOR_H
#define COMPILER_ESEQ_UP_VISITOR_H

#include "irtemplate_visitor.h"
#include "visitor_struct.h"

namespace IRT {
    class ESEQUpVisitor : public IrTemplateVisitor<IrtStorage> {
    public:
        void Visit(ExpStatement *stmt) override;

        void Visit(ConstExpression *const_expression) override;

        void Visit(JumpConditionalStatement *jump_conditional_statement) override;

        void Visit(MoveStatement *move_statement) override;

        void Visit(SeqStatement *seq_statement) override;

        void Visit(LabelStatement *label_statement) override;

        void Visit(BinopExpression *binop_statement) override;

        void Visit(TempExpression *temp_exression) override;

        void Visit(MemExpression *mem_expression) override;

        void Visit(JumpStatement *jump_statement) override;

        void Visit(CallExpression *call_expression) override;

        void Visit(ExpressionList *expression_list) override;

        void Visit(NameExpression *name_expression) override;

        void Visit(EseqExpression *eseq_expression) override;

        Statement *GetTree();

    private:

        static bool IsCommutate(Statement* statement, Expression* expression);
    };

}

#endif //COMPILER_ESEQ_UP_VISITOR_H
