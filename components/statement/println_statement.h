#ifndef COMPILER_PRINTLNSTATEMENT_H
#define COMPILER_PRINTLNSTATEMENT_H

#include "statement.h"

class PrintlnStatement : public Statement {
public:
    PrintlnStatement(Expression* expr) :
        expr_(expr)
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    Expression* expr_;
};

#endif //COMPILER_PRINTLNSTATEMENT_H
