#ifndef COMPILER_BLOCK_H
#define COMPILER_BLOCK_H

#include "irtree/nodes/statements/statement.h"
#include "irtree/nodes/statements/label_statement.h"
#include "irtree/nodes/statements/jump_statement.h"
#include "irtree/nodes/statements/jump_conditional_statement.h"
#include <vector>

namespace IRT {

    class Block {
    public:
        Block();

        void Add(Statement* statement);

        Label InputLabel();

        Label OutputLabel();

        void Accept(IRT::Visitor* visitor);

        bool IsClosed();

    private:
        std::vector<Statement *> statement_list_;
    };

}

#endif //COMPILER_BLOCK_H
