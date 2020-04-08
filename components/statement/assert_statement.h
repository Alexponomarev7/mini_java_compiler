#ifndef COMPILER_ASSERT_STATEMENT_H
#define COMPILER_ASSERT_STATEMENT_H

#include "components/statement/statement.h"

class AssertStatement : public Statement {
public:
    AssertStatement(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    Expression* expr_;

    friend class PrintVisitor;
};

#endif //COMPILER_ASSERT_STATEMENT_H
