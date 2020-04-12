#include "symbol_tree_visitor.h"


#include <iostream>
#include <components/program.h>

#include "types/integer.h"
#include "types/types.h"

SymbolTreeVisitor::SymbolTreeVisitor() :
    tree_(new ScopeLayer())
{
    current_layer_ = tree_.root_;
}

void SymbolTreeVisitor::Visit(Program* program) {
    current_layer_->DeclareVariable(Symbol("int"), "int");
    auto intType = std::make_shared<Integer>();
    intType->MarkType();
    current_layer_->Put(Symbol("int"), intType);

    current_layer_->DeclareVariable(Symbol("bool"), "bool");
    auto boolType = std::make_shared<Boolean>();
    boolType->MarkType();
    current_layer_->Put(Symbol("bool"), boolType);

    current_layer_->DeclareVariable(Symbol("true"), "bool");
    current_layer_->DeclareVariable(Symbol("false"), "bool");

    for (const auto& classObj : program->classes_) {
        current_layer_->DeclareVariable(Symbol(classObj->id_), "class");
        classObj->Accept(this);
        auto classImpl = std::make_shared<ClassType>(classObj->id_, variables_, methods_);
        classImpl->MarkType();
        current_layer_->Put(Symbol(classObj->id_), classImpl);

        variables_.clear();
        methods_.clear();
    }

    program->main_->Accept(this);
}

void SymbolTreeVisitor::Visit(MainClass* mainClass) {
    auto scopeLayer = CreateScopeLayer(this);

    for (const auto& statement : mainClass->statements_) {
        statement->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(Class* classObj) {
    auto scopeLayer = CreateScopeLayer(this);

    for (const auto& declaration : classObj->declarations_) {
        declaration->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(Formal* formal) {
    formals_.push_back({formal->type_, formal->id_});
}

void SymbolTreeVisitor::Visit(MethodInvocation* methodInvocation) {
    std::cout << 1 << std::endl;
    auto type = Accept(methodInvocation->expr_);
    std::cout << type->IsType() << std::endl;
    auto classObj = GetClassOrThrow(type);
    std::cout << 2 << std::endl;

    if (!classObj->HasMethod(methodInvocation->id_)) {
        throw std::runtime_error("Class object has no such method.");
    }
};

void SymbolTreeVisitor::Visit(VariableDeclaration* variableDeclaration) {
    auto type = variableDeclaration->type_;
    auto variable = variableDeclaration->id_;
    variables_.push_back({type, variable});

    auto typeObject = current_layer_->Get(Symbol(type));
    assert(typeObject->IsType());

    current_layer_->DeclareVariable(Symbol(variable), typeObject->GetType());
};

void SymbolTreeVisitor::Visit(MethodDeclaration* methodDeclaration) {
    auto id = methodDeclaration->id_;
    current_layer_->DeclareVariable(Symbol(id), "method");

    auto returnType = methodDeclaration->type_;
    for (const auto& formal : methodDeclaration->formals_) {
        formal->Accept(this);
    }
    auto formals = formals_;
    formals_.clear();

    methods_.push_back({returnType, id, formals});
    auto method = std::make_shared<ClassMethodType>(returnType, id, formals);
    current_layer_->Put(Symbol(id), method);

    auto scopeLayer = CreateScopeLayer(this);
    for (const auto& subStatement : methodDeclaration->statements_) {
        subStatement->Accept(this);
    }
};

void SymbolTreeVisitor::Visit(ArrayMakeExpression* expression) {
    // pass
}

void SymbolTreeVisitor::Visit(BinaryExpression* binaryExpression) {
    auto lvalue = Accept(binaryExpression->leftExpr_);
    auto rvalue = Accept(binaryExpression->rightExpr_);
    EqualTypesOrThrow(lvalue, rvalue);

    std::string binaryOperator = binaryExpression->binaryOperator_;

    std::set<std::string> intOperators = {"+", "-", "%", "/", "*"};
    std::set<std::string> boolOperators = {"||", "&&", "=="};
    std::set<std::string> logicOperators = {"<", ">", "=="};

    if ((lvalue->GetType() == "int") && (intOperators.find(binaryOperator) != intOperators.end())) {
        tos_value_ = std::make_shared<Integer>();
    } else if ((lvalue->GetType() == "bool") && (boolOperators.find(binaryOperator) != boolOperators.end())) {
        tos_value_ = std::make_shared<Boolean>();
    } else if ((lvalue->GetType() == "int") && (logicOperators.find(binaryOperator) != logicOperators.end())) {
        tos_value_ = std::make_shared<Boolean>();
    } else {
        throw std::runtime_error("Incorrect binary operator.");
    }
}

void SymbolTreeVisitor::Visit(InverseExpression* expression) {
    auto value = Accept(expression->expr_);
    GetBoolOrThrow(value);
}

void SymbolTreeVisitor::Visit(MethodInvocationExpression* expression) {
    expression->methodInvocation_->Accept(this);
}

void SymbolTreeVisitor::Visit(ObjectMakeExpression* expression) {
    // pass
}

void SymbolTreeVisitor::Visit(SimpleExpression* expression) {
    tos_value_ = current_layer_->Get(expression->value_);
}

void SymbolTreeVisitor::Visit(NumberExpression *expression) {
    // pass
    tos_value_ = std::make_shared<Integer>();
}

void SymbolTreeVisitor::Visit(LengthExpression* expression) {
    // pass
    tos_value_ = std::make_shared<Boolean>();
}

void SymbolTreeVisitor::Visit(AssertStatement* statement) {
    auto value = Accept(statement->expr_);
    GetBoolOrThrow(value);
}

void SymbolTreeVisitor::Visit(IfElseStatement* statement) {
    auto value = Accept(statement->expr_);
    GetBoolOrThrow(value);

    statement->if_statement_->Accept(this);
    statement->else_statement_->Accept(this);
}

void SymbolTreeVisitor::Visit(IfStatement* statement) {
    auto value = Accept(statement->expr_);
    GetBoolOrThrow(value);

    statement->statement_->Accept(this);
}

void SymbolTreeVisitor::Visit(LocalVariableDeclarationStatement* statement) {
    statement->variableDeclaration_->Accept(this);
}

void SymbolTreeVisitor::Visit(MethodInvocationStatement* statement) {
    std::cout << 1 << std::endl;
    statement->methodInvocation_->Accept(this);
}

void SymbolTreeVisitor::Visit(PrintlnStatement* statement) {
    auto value = Accept(statement->expr_);
    GetIntOrThrow(value);
}

void SymbolTreeVisitor::Visit(ReturnStatement* statement) {
    auto value = Accept(statement->expr_);
    GetIntOrThrow(value);
}

void SymbolTreeVisitor::Visit(ScopeStatements* statement) {
    auto scopeLayer = CreateScopeLayer(this);

    for (const auto& curStatement : statement->statements_) {
        curStatement->Accept(this);
    }
}

void SymbolTreeVisitor::Visit(SetLvalueStatement* statement) {
    auto lvalueType = current_layer_->Get(Symbol(statement->lvalue_));
    auto rvalueType = Accept(statement->expr_);

    EqualTypesOrThrow(lvalueType, rvalueType);
}

void SymbolTreeVisitor::Visit(WhileStatement* statement) {
    auto value = Accept(statement->expr_);
    GetBoolOrThrow(value);

    statement->statement_->Accept(this);
}

ScopeLayer* SymbolTreeVisitor::GetRoot() {
    return current_layer_;
}
