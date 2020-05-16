#ifndef COMPILER_MOVE_STATEMENT_H
#define COMPILER_MOVE_STATEMENT_H

#include "statement.h"
#include "irtree/nodes/expressions/expression.h"

namespace IRT {

    class MoveStatement : public Statement {
    public:
        MoveStatement(Expression *source, Expression *target);
        void Accept(Visitor *visitor) override;
        Expression* source_;
        Expression* target_;
    };

};

#endif //COMPILER_MOVE_STATEMENT_H
