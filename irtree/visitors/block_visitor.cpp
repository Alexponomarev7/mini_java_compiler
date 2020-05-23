#include "block_visitor.h"

#include "base_elements.h"
#include <iostream>

namespace IRT {

    void BlockVisitor::AddToBlock(IRT::Statement *statement) {
        auto label_statement = dynamic_cast<LabelStatement*>(statement);

        std::cout << "BLOCKS: " << blocks_.size() << std::endl;
        if (label_statement) {
            if (!blocks_.empty()) {
                if (!blocks_.back()->IsClosed()) {
                    blocks_.back()->Add(
                        new JumpStatement(
                            label_statement->label_
                        )
                    );
                }
            }

            auto block = new Block();
            block->Add(label_statement);
            blocks_.push_back(block);
            return;
        }

        blocks_.back()->Add(statement);
    }

    std::vector<Block*> BlockVisitor::GetBlocks() {
        if (!blocks_.empty() && !blocks_.back()->IsClosed()) {
            blocks_.back()->Add(
                new JumpStatement(
                    Label("done")
                )
            );
        }

        return blocks_;
    }

    void BlockVisitor::Visit(ExpStatement *stmt) {
        IrtStorage elements = Accept(stmt->GetExpression());
        tos_value_.statement_ = new ExpStatement(elements.expression_);

        std::cout << "EXP" << std::endl;
        AddToBlock(tos_value_.statement_);
        std::cout << "EXITED" << std::endl;
    }

    void BlockVisitor::Visit(ConstExpression *const_expression) {
        tos_value_.expression_ = new ConstExpression(const_expression->Value());
    }

    void BlockVisitor::Visit(JumpConditionalStatement *jump_conditional_statement) {
        auto lhs = Accept(jump_conditional_statement->left_operand_).expression_;
        auto rhs = Accept(jump_conditional_statement->right_operand_).expression_;

        tos_value_.statement_ = new JumpConditionalStatement(
                jump_conditional_statement->operator_type_,
                lhs,
                rhs,
                jump_conditional_statement->label_true_,
                jump_conditional_statement->label_false_
        );

        std::cout << "JCB" << std::endl;
        AddToBlock(tos_value_.statement_);
        std::cout << "EXITED" << std::endl;
    }
    void BlockVisitor::Visit(MoveStatement *move_statement) {
        auto source = Accept(move_statement->source_).expression_;
        auto target = Accept(move_statement->target_).expression_;

        tos_value_.statement_ = new MoveStatement(source, target);
        std::cout << "MVS" << std::endl;
        AddToBlock(tos_value_.statement_);
        std::cout << "EXITED" << std::endl;
    }

    void BlockVisitor::Visit(SeqStatement *seq_statement) {
        auto first = Accept(seq_statement->first_statement_).statement_;
        auto second = Accept(seq_statement->second_statement_).statement_;

        tos_value_.statement_ = new SeqStatement(
                first,
                second
        );
    }


    void BlockVisitor::Visit(LabelStatement *label_statement) {
        tos_value_.statement_ = new LabelStatement(label_statement->label_);
        std::cout << "LABEL" << std::endl;
        AddToBlock(tos_value_.statement_);
        std::cout << "EXITED" << std::endl;
    }

    void BlockVisitor::Visit(BinopExpression *binop_statement) {
        tos_value_.expression_ = new BinopExpression(
                binop_statement->operator_type_,
                Accept(binop_statement->first_).expression_,
                Accept(binop_statement->second_).expression_
        );
    }
    void BlockVisitor::Visit(TempExpression *temp_exression) {
        tos_value_.expression_ = new TempExpression(temp_exression->temporary_);
    }

    void BlockVisitor::Visit(MemExpression *mem_expression) {
        tos_value_.expression_ = new MemExpression(
                Accept(mem_expression->expression_).expression_
        );
    }

    void BlockVisitor::Visit(JumpStatement *jump_statement) {
        tos_value_.statement_ = new JumpStatement(
                jump_statement->label_
        );
        std::cout << "JUMP" << std::endl;
        AddToBlock(tos_value_.statement_);
        std::cout << "EXITED" << std::endl;
    }
    void BlockVisitor::Visit(CallExpression *call_expression) {
        auto func = Accept(call_expression->function_name_).expression_;
        auto args = Accept(call_expression->args_).expression_list_;

        tos_value_.expression_ = new CallExpression(
            func,
            args
        );
    }

    void BlockVisitor::Visit(ExpressionList *expression_list) {
        auto expression_list_ = new ExpressionList();

        for (auto expression: expression_list->expressions_) {
            expression_list_->Add(Accept(expression).expression_);
        }
        tos_value_.expression_list_ = expression_list_;
    }

    void BlockVisitor::Visit(NameExpression *name_expression) {
        tos_value_.expression_ = new NameExpression(name_expression->label_);
    }

    void BlockVisitor::Visit(EseqExpression *eseq_expression) {
        auto stmt = Accept(eseq_expression->statement_).statement_;
        auto expr = Accept(eseq_expression->expression_).expression_;

        tos_value_.expression_ = new EseqExpression(stmt, expr);
    }

    Statement *BlockVisitor::GetTree() {
        return tos_value_.statement_;
    }

}
