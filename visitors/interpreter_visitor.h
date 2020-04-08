#ifndef COMPILER_INTERPRETER_H
#define COMPILER_INTERPRETER_H

#include "visitor.h"

#include <map>
#include <exception>
#include <iostream>
#include <vector>
#include <cassert>

class InterpreterVisitor : public Visitor {
public:
    InterpreterVisitor();

    void Visit(Program* program) override;

    void Visit(MainClass* mainClass) override;
    void Visit(Class* classObj) override;
    void Visit(Formal* formal) override;
    void Visit(MethodInvocation* methodInvocation) override;

    void Visit(VariableDeclaration* variableDeclaration) override;
    void Visit(MethodDeclaration* methodDeclaration) override;

    void Visit(ArrayMakeExpression* expression) override;
    void Visit(BinaryExpression* expression) override;
    void Visit(InverseExpression* expression) override;
    void Visit(MethodInvocationExpression* expression) override;
    void Visit(ObjectMakeExpression* expression) override;
    void Visit(SimpleExpression* expression) override;
    void Visit(LengthExpression* expression) override;

    void Visit(AssertStatement* statement) override;
    void Visit(IfElseStatement* statement) override;
    void Visit(IfStatement* statement) override;
    void Visit(LocalVariableDeclarationStatement* statement) override;
    void Visit(MethodInvocationStatement* statement) override;
    void Visit(PrintlnStatement* statement) override;
    void Visit(ReturnStatement* statement) override;
    void Visit(ScopeStatements* statement) override;
    void Visit(SetLvalueStatement* statement) override;
    void Visit(WhileStatement* statement) override;

private:
    std::vector<std::map<Identifier, int>> variables_;
    std::vector<std::map<Identifier, std::string>> types_;

    std::string lastType_;
    int lastValue_;

    static bool IsNumber_(const std::string& value);

    int LoadInt_();
    bool LoadBool_();

    void SaveInt_(int value);
    void SaveBool_(bool value);

    std::pair<std::string, int> Load_();
    void Save_(std::string type, int value);
};

#endif //COMPILER_PRINTER_H
