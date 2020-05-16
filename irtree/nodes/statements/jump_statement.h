#ifndef COMPILER_JUMP_STATEMENT_H
#define COMPILER_JUMP_STATEMENT_H

#include "statement.h"
#include "irtree/generators/label.h"

namespace IRT {

    class JumpStatement : public Statement {
    public:
        explicit JumpStatement(Label label);
        void Accept(Visitor *visitor) override;
        Label label_;

    };
}


#endif //COMPILER_JUMP_STATEMENT_H
