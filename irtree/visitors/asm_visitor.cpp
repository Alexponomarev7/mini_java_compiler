#include "asm_visitor.h"

#include "base_elements.h"
#include <iostream>

namespace IRT {

    AsmVisitor::AsmVisitor(const std::string &filename) :
            stream_(filename) {
    }

    void AsmVisitor::Visit(ExpStatement *stmt) {
        stmt->GetExpression()->Accept(this);
    }

    void AsmVisitor::Visit(ConstExpression *const_expression) {
        auto reg = Registry();

        stream_ << "mov " << reg.ToString() << ", #" << const_expression->Value() << std::endl;
        tos_value_ = reg;
    }

    void AsmVisitor::Visit(JumpConditionalStatement *jump_conditional_statement) {
        auto left_reg = Accept(jump_conditional_statement->left_operand_);
        auto right_reg = Accept(jump_conditional_statement->right_operand_);

        stream_ << "cmp " << left_reg.ToString() << ", " << right_reg.ToString() << std::endl;
        stream_ << "j" << SuffixAsm(jump_conditional_statement->operator_type_) << " "
        << jump_conditional_statement->label_true_.ToString() << std::endl;
    }

    void AsmVisitor::Visit(MoveStatement *move_statement) {
        auto source_reg = Accept(move_statement->source_);
        auto target_reg = Accept(move_statement->target_);

        stream_ << "mov " << target_reg.ToString() << ", " << source_reg.ToString() << std::endl;
    }

    void AsmVisitor::Visit(SeqStatement *seq_statement) {
        seq_statement->first_statement_->Accept(this);
        seq_statement->second_statement_->Accept(this);
    }

    void AsmVisitor::Visit(LabelStatement *label_statement) {
        stream_ << label_statement->label_.ToString() << ":" << std::endl;
    }

    void AsmVisitor::Visit(BinopExpression *binop_statement) {
        auto target_reg = Registry();
        auto left_reg = Accept(binop_statement->first_);
        auto right_reg = Accept(binop_statement->second_);

        stream_ << OperatorAsm(binop_statement->operator_type_) << " " << target_reg.ToString() << ", ";
        stream_ << left_reg.ToString() << ", ";
        stream_ << right_reg.ToString() << std::endl;

        tos_value_ = target_reg;
    }

    void AsmVisitor::Visit(TempExpression *temp_exression) {
        auto reg = Registry();

        if (temp_exression->temporary_.ToString() == "::fp") {
            stream_ << "mov " << reg.ToString() << ", " << ToASM(Reg::FramePointer) << std::endl;
            tos_value_ = reg;
            return;
        }

        // TODO: fix
        //assert(false);
        tos_value_ = Registry(temp_exression->temporary_.ToString());
    }

    void AsmVisitor::Visit(MemExpression *mem_expression) {
        auto reg = Accept(mem_expression->expression_);
        tos_value_ = Registry("[" + reg.ToString() + "]");
    }

    void AsmVisitor::Visit(JumpStatement *jump_statement) {
        stream_ << "jmp " << jump_statement->label_.ToString() << std::endl;
    }

    void AsmVisitor::Visit(CallExpression *call_expression) {
        auto func_name = Accept(call_expression->function_name_);
        call_expression->args_->Accept(this);

        stream_ << "call " << func_name.ToString() << std::endl;
    }

    void AsmVisitor::Visit(ExpressionList *expression_list) {
        for (auto expression: expression_list->expressions_) {
            auto reg = Accept(expression);
            stream_ << "push " << reg.ToString() << std::endl;
        }
    }

    void AsmVisitor::Visit(NameExpression *name_expression) {
         tos_value_ = Registry(name_expression->label_.ToString());
    }

    AsmVisitor::~AsmVisitor() {
        stream_.close();
    }

    void AsmVisitor::Visit(EseqExpression *eseq_expression) {
        assert(false);
    }

}
