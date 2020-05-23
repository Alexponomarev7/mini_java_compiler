#include "eseq_up_visitor.h"

#include "base_elements.h"
#include <algorithm>
#include <iostream>

namespace IRT {

    void ESEQUpVisitor::Visit(ExpStatement *stmt) {
        IrtStorage elements = Accept(stmt->GetExpression());
        tos_value_.statement_ = new ExpStatement(elements.expression_);
    }

    void ESEQUpVisitor::Visit(ConstExpression *const_expression) {
        tos_value_.expression_ = new ConstExpression(const_expression->Value());
    }

    void ESEQUpVisitor::Visit(JumpConditionalStatement *jump_conditional_statement) {
        auto lhs = Accept(jump_conditional_statement->left_operand_).expression_;
        auto rhs = Accept(jump_conditional_statement->right_operand_).expression_;

        tos_value_.statement_ = new JumpConditionalStatement(
            jump_conditional_statement->operator_type_,
            lhs,
            rhs,
            jump_conditional_statement->label_true_,
            jump_conditional_statement->label_false_
        );
    }

    void ESEQUpVisitor::Visit(MoveStatement *move_statement) {
        auto source = Accept(move_statement->source_).expression_;
        auto target = Accept(move_statement->target_).expression_;

        tos_value_.statement_ = new MoveStatement(source, target);
    }

    void ESEQUpVisitor::Visit(SeqStatement *seq_statement) {
        auto first = Accept(seq_statement->first_statement_).statement_;
        auto second = Accept(seq_statement->second_statement_).statement_;

        tos_value_.statement_ = new SeqStatement(
            first,
            second
        );
    }


    void ESEQUpVisitor::Visit(LabelStatement *label_statement) {
        tos_value_.statement_ = new LabelStatement(label_statement->label_);
    }

    void ESEQUpVisitor::Visit(BinopExpression *binop_statement) {
        auto eseq_expression = dynamic_cast<EseqExpression*>(binop_statement->first_);

        if (eseq_expression) {
            tos_value_.expression_ = Accept(new EseqExpression(
                eseq_expression->statement_,
                new BinopExpression(
                    binop_statement->operator_type_,
                    eseq_expression->expression_,
                    binop_statement->second_
                )
            )).expression_;
            return;
        }

        eseq_expression = dynamic_cast<EseqExpression*>(binop_statement->second_);

        if (eseq_expression) {
            if (IsCommutate(eseq_expression->statement_, binop_statement->first_)) {
                tos_value_.expression_ = Accept(new EseqExpression(
                    eseq_expression->statement_,
                new BinopExpression(
                        binop_statement->operator_type_,
                        binop_statement->first_,
                        eseq_expression->expression_
                    )
                )).expression_;
                return;
            }

            auto temp = Temporary();
            tos_value_.expression_ = Accept(new EseqExpression(
                new MoveStatement(
                    new TempExpression(temp),
                    binop_statement->first_
                ),
                new EseqExpression(
                    eseq_expression->statement_,
                    new BinopExpression(
                        binop_statement->operator_type_,
                        new TempExpression(temp),
                        eseq_expression->expression_
                    )
                )
            )).expression_;
            return;
        }

        tos_value_.expression_ = new BinopExpression(
                binop_statement->operator_type_,
                Accept(binop_statement->first_).expression_,
                Accept(binop_statement->second_).expression_
        );
    }

    void ESEQUpVisitor::Visit(TempExpression *temp_exression) {
        tos_value_.expression_ = new TempExpression(temp_exression->temporary_);
    }

    void ESEQUpVisitor::Visit(MemExpression *mem_expression) {
        tos_value_.expression_ = new MemExpression(
                Accept(mem_expression->expression_).expression_
        );
    }

    void ESEQUpVisitor::Visit(JumpStatement *jump_statement) {
        tos_value_.statement_ = new JumpStatement(
                jump_statement->label_
        );
    }

    void ESEQUpVisitor::Visit(CallExpression *call_expression) {
        auto func = Accept(call_expression->function_name_).expression_;
        auto args = Accept(call_expression->args_).expression_list_;

        auto expression_list_ = new ExpressionList();
        auto statements_list_ = std::vector<Statement*>();

        bool is_eseq_exists = false;
        bool is_conflict = false;
        EseqExpression* eseq = nullptr;

        for (int i = args->expressions_.size() - 1; i >= 0; i--) {
            auto expression = args->expressions_[i];
            auto eseq_expression = dynamic_cast<EseqExpression *>(expression);

            if (is_eseq_exists) {
                if (!is_conflict && !IsCommutate(eseq->statement_, expression)) {
                    is_conflict = true;
                }

                if (is_conflict) {
                    auto temp = Temporary();
                    statements_list_.push_back(new MoveStatement(
                            new TempExpression(temp),
                            Accept(expression).expression_
                    ));

                    expression_list_->Add(new TempExpression(temp));
                    continue;
                }
            }

            if (!is_eseq_exists && eseq_expression) {
                is_eseq_exists = true;
                eseq = eseq_expression;

                statements_list_.push_back(Accept(eseq->statement_).statement_);
                expression_list_->Add(Accept(eseq->expression_).expression_);
                continue;
            }

            expression_list_->Add(Accept(expression).expression_);
        }

        std::reverse(expression_list_->expressions_.begin(), expression_list_->expressions_.end());

        if (is_eseq_exists) {
            auto statement = Accept(statements_list_.back()).statement_;

            for (int i = (int)statements_list_.size() - 1; i >= 0; i--) {
                statement = new SeqStatement(
                        statements_list_[i],
                        statement
                );
            }

            tos_value_.expression_ = Accept(new EseqExpression(
                    statement,
                    new CallExpression(
                        func,
                        expression_list_
                    )
            )).expression_;

            return;
        }

        tos_value_.expression_ = new CallExpression(
            func,
            args
        );
    }

    void ESEQUpVisitor::Visit(ExpressionList *expression_list) {
        auto expression_list_ = new ExpressionList();

        for (auto expression: expression_list->expressions_) {
            expression_list_->Add(Accept(expression).expression_);
        }

        tos_value_.expression_list_ = expression_list_;
    }

    void ESEQUpVisitor::Visit(NameExpression *name_expression) {
        tos_value_.expression_ = new NameExpression(name_expression->label_);
    }

    void ESEQUpVisitor::Visit(EseqExpression *eseq_expression) {
        auto stmt = Accept(eseq_expression->statement_).statement_;
        auto expr = Accept(eseq_expression->expression_).expression_;

        auto eseq_expr = dynamic_cast<EseqExpression *>(expr);

        if (eseq_expr) {
            tos_value_.expression_ = Accept(new EseqExpression(
                    new SeqStatement(
                            eseq_expression->statement_,
                            eseq_expr->statement_
                    ),
                    eseq_expr->expression_
            )).expression_;
            return;
        }

        tos_value_.expression_ = new EseqExpression(stmt, expr);
    }

    Statement *ESEQUpVisitor::GetTree() {
        return tos_value_.statement_;
    }

    bool ESEQUpVisitor::IsCommutate(Statement* statement, Expression* expression) {
        auto const_expr = dynamic_cast<ConstExpression*>(expression);
        if (const_expr) {
            return true;
        }

        auto name_expr = dynamic_cast<NameExpression*>(expression);
        if (name_expr) {
            return true;
        }

        auto expr_statement = dynamic_cast<ExpStatement*>(statement);
        if (expr_statement) {
            const_expr = dynamic_cast<ConstExpression*>(expr_statement->GetExpression());
            if (const_expr) {
                return true;
            }
        }

        return false;
    }

}