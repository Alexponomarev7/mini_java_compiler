#ifndef COMPILER_LOCAL_VARIABLE_DECLARATION_STATEMENT_H
#define COMPILER_LOCAL_VARIABLE_DECLARATION_STATEMENT_H

#include "components/statement/statement.h"

class LocalVariableDeclarationStatement : public Statement {
public:
    LocalVariableDeclarationStatement(VariableDeclaration* variableDeclaration) :
        variableDeclaration_(variableDeclaration)
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    VariableDeclaration* variableDeclaration_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_LOCAL_VARIABLE_DECLARATION_STATEMENT_H
