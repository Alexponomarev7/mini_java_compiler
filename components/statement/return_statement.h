#ifndef COMPILER_RETURN_STATEMENT_H
#define COMPILER_RETURN_STATEMENT_H

#include "statement.h"

class ReturnStatement : public Statement {
public:
    ReturnStatement(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) override {
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
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_RETURN_STATEMENT_H
