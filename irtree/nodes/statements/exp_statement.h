#ifndef COMPILER_EXP_STATEMENT_H
#define COMPILER_EXP_STATEMENT_H

#include "statement.h"
#include "irtree/nodes/expressions/expression.h"


namespace IRT {

    class ExpStatement : public Statement {
    public:
        explicit ExpStatement(Expression* expression);
        Expression* GetExpression();
        ~ExpStatement() override = default;
        void Accept(Visitor *visitor) override;

    private:
        Expression* expression_;
    };

}

#endif //COMPILER_EXP_STATEMENT_H
