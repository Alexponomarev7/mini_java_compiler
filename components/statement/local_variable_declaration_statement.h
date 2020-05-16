#ifndef COMPILER_LOCAL_VARIABLE_DECLARATION_STATEMENT_H
#define COMPILER_LOCAL_VARIABLE_DECLARATION_STATEMENT_H

#include "components/statement/statement.h"

class LocalVariableDeclarationStatement : public Statement {
public:
    LocalVariableDeclarationStatement(VariableDeclaration* variableDeclaration) :
        variableDeclaration_(variableDeclaration)
    {}

    void Accept(Visitor* visitor) {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    VariableDeclaration* variableDeclaration_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
    friend class IrtreeBuildVisitor;
};

#endif //COMPILER_LOCAL_VARIABLE_DECLARATION_STATEMENT_H
