#include <components/program.h>
#include "print_visitor.h"

PrintVisitor::PrintVisitor(const std::string& filename) :
    stream_(filename)
{}

void PrintVisitor::Visit(Program* program) {
    stream_ << "Program:" << std::endl;
    auto addTab = AddTab(this);

    program->main_->Accept(this);

    for (const auto& classObj : program->classes_) {
        classObj->Accept(this);
    }
}

void PrintVisitor::Visit(MainClass* mainClass) {
    PrintTabs_();

    stream_ << "Main class <" << mainClass->id_ << ">:" << std::endl;
    auto addTab = AddTab(this);

    for (const auto& statement : mainClass->statements_) {
        statement->Accept(this);
    }
}

void PrintVisitor::Visit(Class* classObj) {
    PrintTabs_();

    stream_ << "Class <" << classObj->id_ << ">:" << std::endl;
    auto addTab = AddTab(this);

    if (!classObj->extension_.empty()) {
        PrintTabs_();
        stream_ << "Extension <" << classObj->extension_ << ">:" << std::endl;
    }

    for (const auto& declaration : classObj->declarations_) {
        declaration->Accept(this);
    }
}

void PrintVisitor::Visit(Formal* formal) {
    PrintTabs_();

    stream_ << formal->type_ << " " << formal->id_ << std::endl;
}

void PrintVisitor::Visit(MethodInvocation* methodInvocation) {
    PrintTabs_();

    stream_ << "Method invocation <" << methodInvocation->id_ << ">:" << std::endl;
    auto addTab = AddTab(this);
}

void PrintVisitor::Visit(VariableDeclaration* variableDeclaration) {
    PrintTabs_();

    stream_ << "Variable declaration <" << variableDeclaration->type_ << " "
        << variableDeclaration->id_ << ">:" << std::endl;
}

void PrintVisitor::Visit(MethodDeclaration* methodDeclaration) {
    PrintTabs_();
    stream_ << "Method declaration <" << methodDeclaration->type_ << " "
        << methodDeclaration->id_ <<  ">:" << std::endl;;

    {
        PrintTabs_();
        stream_ << "Method formals:" << std::endl;
        auto addTab = AddTab(this);

        for (const auto &formal : methodDeclaration->formals_) {
            formal->Accept(this);
        }
    }

    {
        PrintTabs_();
        stream_ << "Method statements:" << std::endl;
        auto addTab = AddTab(this);

        for (const auto &statement : methodDeclaration->statements_) {
            statement->Accept(this);
        }
    }
}

void PrintVisitor::Visit(ArrayMakeExpression* arrayMakeExpression) {
    PrintTabs_();

    stream_ << "Array make expression <" << arrayMakeExpression->simpleType_ << ">:" << std::endl;
    auto addTab = AddTab(this);

    arrayMakeExpression->sizeExpr_->Accept(this);
}

void PrintVisitor::Visit(BinaryExpression* binaryExpression) {
    PrintTabs_();

    stream_ << "Binary expression <" << binaryExpression->binaryOperator_ << ">:" << std::endl;
    auto addTab = AddTab(this);

    binaryExpression->leftExpr_->Accept(this);
    binaryExpression->rightExpr_->Accept(this);
}

void PrintVisitor::Visit(InverseExpression* inverseExpression) {
    PrintTabs_();

    stream_ << "Inverse expression:" << std::endl;
    auto addTab = AddTab(this);

    inverseExpression->expr_->Accept(this);
}

void PrintVisitor::Visit(MethodInvocationExpression* methodInvocationExpression) {
    PrintTabs_();

    stream_ << "Method invocation expression:" << std::endl;
    auto addTab = AddTab(this);

    methodInvocationExpression->methodInvocation_->Accept(this);
}

void PrintVisitor::Visit(ObjectMakeExpression* objectMakeExpression) {
    PrintTabs_();

    stream_ << "Object make expression<" << objectMakeExpression->typeIdentifier_ << ">:" << std::endl;
}

void PrintVisitor::Visit(SimpleExpression* simpleExpression) {
    PrintTabs_();

    stream_ << "Simple expression<" << simpleExpression->value_ << ">:" << std::endl;
}

void PrintVisitor::Visit(AssertStatement* statement) {
    PrintTabs_();

    stream_ << "Assert statement:" << std::endl;
    auto addTab = AddTab(this);

    statement->expr_->Accept(this);
}

void PrintVisitor::Visit(IfElseStatement* statement) {
    PrintTabs_();
    stream_ << "If expression:" << std::endl;
    {
        auto addTab = AddTab(this);
        statement->expr_->Accept(this);
    }

    PrintTabs_();
    stream_ << "If statement:" << std::endl;
    {
        auto addTab = AddTab(this);
        statement->if_statement_->Accept(this);
    }

    PrintTabs_();
    stream_ << "Else statement:" << std::endl;
    {
        auto addTab = AddTab(this);
        statement->else_statement_->Accept(this);
    }
}

void PrintVisitor::Visit(IfStatement* statement) {
    PrintTabs_();
    stream_ << "If expression:" << std::endl;
    {
        auto addTab = AddTab(this);
        statement->expr_->Accept(this);
    }

    PrintTabs_();
    stream_ << "If statement:" << std::endl;
    {
        auto addTab = AddTab(this);
        statement->statement_->Accept(this);
    }
}

void PrintVisitor::Visit(LocalVariableDeclarationStatement* statement) {
    PrintTabs_();

    stream_ << "Local variable declaration statement:" << std::endl;
    auto addTab = AddTab(this);
    statement->variableDeclaration_->Accept(this);
}

void PrintVisitor::Visit(MethodInvocationStatement* statement) {
    PrintTabs_();

    stream_ << "Method invocation statement:" << std::endl;
    auto addTab = AddTab(this);
    statement->methodInvocation_->Accept(this);
}

void PrintVisitor::Visit(PrintlnStatement* statement) {
    PrintTabs_();

    stream_ << "Println statement:" << std::endl;
    auto addTab = AddTab(this);
    statement->expr_->Accept(this);
}

void PrintVisitor::Visit(ReturnStatement* statement) {
    PrintTabs_();

    stream_ << "Return statement:" << std::endl;
    auto addTab = AddTab(this);
    statement->expr_->Accept(this);
}

void PrintVisitor::Visit(ScopeStatements* statement) {
    PrintTabs_();

    stream_ << "Scope statements:" << std::endl;
    auto addTab = AddTab(this);
    for (const auto& subStatement : statement->statements_) {
        subStatement->Accept(this);
    }
}

void PrintVisitor::Visit(SetLvalueStatement* statement) {
    PrintTabs_();

    stream_ << "Set lvalue statement<" << statement->lvalue_ << ">:" << std::endl;
    auto addTab = AddTab(this);

    statement->expr_->Accept(this);
}

void PrintVisitor::Visit(WhileStatement* statement) {
    PrintTabs_();

    stream_ << "While expression:" << std::endl;
    {
        auto addTab = AddTab(this);
        statement->expr_->Accept(this);
    }

    PrintTabs_();
    stream_ << "While statement:" << std::endl;
    {
        auto addTab = AddTab(this);
        statement->statement_->Accept(this);
    }
}

void PrintVisitor::PrintTabs_() {
    for (size_t i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}