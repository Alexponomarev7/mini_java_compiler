#ifndef COMPILER_PRINTER_H
#define COMPILER_PRINTER_H

#include "visitor.h"
#include <fstream>

class PrintVisitor : public Visitor {
public:
    PrintVisitor(const std::string& filename);

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
    struct AddTab {
        explicit AddTab(PrintVisitor* visitor) : visitor_(visitor) {
            visitor_->num_tabs_++;
        }

        ~AddTab() {
            visitor_->num_tabs_--;
        }

        PrintVisitor* visitor_;
    };

    void PrintTabs_();

    std::ofstream stream_;
    int num_tabs_ = 0;
};

#endif //COMPILER_PRINTER_H
