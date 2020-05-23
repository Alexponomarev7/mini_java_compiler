#include "block.h"
#include <cassert>
#include <iostream>

namespace IRT {

    Block::Block() {
    }

    void Block::Add(Statement *statement) {
        std::cout << "HI" << std::endl;
        std::cout << statement_list_.size() << std::endl;
        if (statement_list_.empty()) {
            auto label_statement = dynamic_cast<LabelStatement*>(statement);
            assert(label_statement != nullptr);
        }

        assert(!IsClosed());
        statement_list_.push_back(statement);
    }

    Label Block::InputLabel() {
        assert(IsClosed());

        auto label_statement = dynamic_cast<LabelStatement*>(statement_list_[0]);
        return label_statement->label_;
    }

    Label Block::OutputLabel() {
        assert(IsClosed());

        auto jmp_statement = dynamic_cast<JumpStatement*>(statement_list_.back());
        if (jmp_statement) {
            return jmp_statement->label_;
        }

        auto cond_jmp_statement = dynamic_cast<JumpConditionalStatement*>(statement_list_.back());
        if (cond_jmp_statement) {
            return cond_jmp_statement->label_false_;
        }

        assert(false);
    }

    void Block::Accept(IRT::Visitor* visitor) {
        for (auto statement : statement_list_) {
            statement->Accept(visitor);
        }
    }

    bool Block::IsClosed() {
        if (statement_list_.size() < 2) {
            return false;
        }

        auto jump_statement = dynamic_cast<JumpStatement*>(statement_list_.back());
        auto cond_jump_statement = dynamic_cast<JumpConditionalStatement*>(statement_list_.back());

        return jump_statement != nullptr || cond_jump_statement != nullptr;
    }

}