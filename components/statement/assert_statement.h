#ifndef COMPILER_ASSERT_STATEMENT_H
#define COMPILER_ASSERT_STATEMENT_H

#include "components/statement/statement.h"

class AssertStatement : public Statement {
public:
    AssertStatement(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Expression* expr_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_ASSERT_STATEMENT_H
