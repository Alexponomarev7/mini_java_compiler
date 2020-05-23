#ifndef COMPILER_BLOCK_VISITOR_H
#define COMPILER_BLOCK_VISITOR_H

#include "irtemplate_visitor.h"
#include "visitor_struct.h"
#include <vector>
#include "irtree/helpers/block.h"
#include "irtree/helpers/trace.h"

namespace IRT {
    class BlockVisitor : public IrTemplateVisitor<IrtStorage> {
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

        std::vector<Block*> GetBlocks();

    private:

        void AddToBlock(Statement* statement);

        std::vector<Block*> blocks_;
    };
}

#endif //COMPILER_BLOCK_VISITOR_H
