//
// Created by Alexey A. Ponomarev on 03.05.2020.
//

#include "function_call_visitor.h"

FunctionCallVisitor::FunctionCallVisitor(ScopeLayer* function_scope, std::shared_ptr<ClassMethodType> function)
    : root_layer(function_scope), frame(function)
{
    //current_layer_->Put(Symbol("true"), std::make_shared<Boolean>(true));
    //current_layer_->Put(Symbol("false"), std::make_shared<Boolean>(false));

    current_layer_ = root_layer;
    offsets_.push(0);

    // init built-in variables
    size_t index = frame.AllocVariable();
    table_.CreateVariable(Symbol("true"));
    table_.Put(Symbol("true"), index);
    frame.Set(index, std::make_shared<Boolean>(true));

    index = frame.AllocVariable();
    table_.CreateVariable(Symbol("false"));
    table_.Put(Symbol("false"), index);
    frame.Set(index, std::make_shared<Boolean>(false));
}

void FunctionCallVisitor::Visit(Program* program) {
    for (const auto& classObj : program->classes_) {
        classObj->Accept(this);
    }

    program->main_->Accept(this);
}

void FunctionCallVisitor::Visit(MainClass* mainClass) {

    std::cerr << "Going inside Main Class" << std::endl;
    current_layer_ = current_layer_->GetChild(offsets_.top());
    offsets_.push(0);
    frame.AllocScope();
    table_.BeginScope();
    // Start main method
    for (const auto &statement : mainClass->statements_) {
        statement->Accept(this);
    }
    // End main method
    offsets_.pop();
    size_t index = offsets_.top();

    offsets_.pop();
    offsets_.push(index + 1);

    current_layer_ = current_layer_->GetParent();
    frame.DeallocScope();
    table_.EndScope();
}

void FunctionCallVisitor::Visit(Class* classObj) {
    std::cerr << "Going inside" << std::endl;
    current_layer_ = current_layer_->GetChild(offsets_.top());
    offsets_.push(0);
    frame.AllocScope();
    table_.BeginScope();

    offsets_.pop();
    size_t index = offsets_.top();

    offsets_.pop();
    offsets_.push(index + 1);

    current_layer_ = current_layer_->GetParent();
    frame.DeallocScope();
    table_.EndScope();
}

void FunctionCallVisitor::Visit(Formal* formal) {
    // pass
}

void FunctionCallVisitor::Visit(MethodInvocation* methodInvocation) {
    std::cerr << "Function called " << methodInvocation->id_ << std::endl;
    auto function_type = tree_->GetFunctionScopeByName(methodInvocation->id_)->Get(methodInvocation->id_);

    std::shared_ptr<ClassMethodType> func_converted = std::dynamic_pointer_cast<ClassMethodType>(function_type);

    if (func_converted == nullptr) {
        throw std::runtime_error("Function not defined");
    }

    std::vector<int> params;

    // TODO: Add params to invocation
    //auto methodParams = Accept(methodInvocation->expr_);

    //for (auto param : methodParams) {
    //    params.push_back(Accept(param));
    //}

    FunctionCallVisitor new_visitor(
        tree_->GetFunctionScopeByName(methodInvocation->id_),
        func_converted
    );

    //new_visitor.SetParams(params);

    new_visitor.GetFrame().SetParentFrame(&frame);
    new_visitor.Visit(FunctionStorage::GetInstance().Get(Symbol(methodInvocation->id_)));


    tos_value_ = frame.GetReturnValue();
}

void FunctionCallVisitor::Visit(VariableDeclaration* variableDeclaration) {
    size_t index = frame.AllocVariable();
    table_.CreateVariable(Symbol(variableDeclaration->id_));
    table_.Put(Symbol(variableDeclaration->id_), index);
}

void FunctionCallVisitor::Visit(MethodDeclaration* methodDeclaration) {
    // TODO: fix
    for (auto statement : methodDeclaration->statements_) {
        statement->Accept(this);
    }
}

void FunctionCallVisitor::Visit(ArrayMakeExpression* arrayMakeExpression) {
    auto length = GetIntOrThrow(Accept(arrayMakeExpression->sizeExpr_));
    auto simpleType = current_layer_->Get(arrayMakeExpression->simpleType_);
    tos_value_ = std::make_shared<Array>(simpleType, length);
    // pass
}

void FunctionCallVisitor::Visit(BinaryExpression* binaryExpression) {
    auto leftResult = Accept(binaryExpression->leftExpr_);
    auto rightResult = Accept(binaryExpression->rightExpr_);

    if (binaryExpression->binaryOperator_ == "+") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) + GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "-") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) - GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "*") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) * GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "/") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) / GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "%") {
        tos_value_ = std::make_shared<Integer>(GetIntOrThrow(leftResult) % GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "&&") {
        tos_value_ = std::make_shared<Boolean>(GetBoolOrThrow(leftResult) && GetBoolOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "||") {
        tos_value_ = std::make_shared<Boolean>(GetBoolOrThrow(leftResult) || GetBoolOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "==") {
        tos_value_ = std::make_shared<Boolean>(GetIntOrThrow(leftResult) == GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == "<") {
        tos_value_ = std::make_shared<Boolean>(GetIntOrThrow(leftResult) < GetIntOrThrow(rightResult));
    } else if (binaryExpression->binaryOperator_ == ">") {
        tos_value_ = std::make_shared<Boolean>(GetIntOrThrow(leftResult) > GetIntOrThrow(rightResult));
    } else {
        throw std::runtime_error("Unknown binary operator");
    }
}

void FunctionCallVisitor::Visit(InverseExpression* inverseExpression) {
    auto result = GetBoolOrThrow(Accept(inverseExpression->expr_));
    tos_value_ = std::make_shared<Boolean>(!result);
}

void FunctionCallVisitor::Visit(MethodInvocationExpression* methodInvocationExpression) {
    methodInvocationExpression->methodInvocation_->Accept(this);
}

void FunctionCallVisitor::Visit(ObjectMakeExpression* objectMakeExpression) {
    // pass
    tos_value_ = current_layer_->Get(Symbol(objectMakeExpression->typeIdentifier_));
}

void FunctionCallVisitor::Visit(NumberExpression* numberExpression) {
    tos_value_ = std::make_shared<Integer>(numberExpression->value_);
}

void FunctionCallVisitor::Visit(SimpleExpression* simpleExpression) {
    int index = table_.Get(Symbol(simpleExpression->value_));
    tos_value_ = frame.Get(index);
}

void FunctionCallVisitor::Visit(LengthExpression* lengthExpression) {
    // pass
    auto array = GetArrayOrThrow(Accept(lengthExpression->expr_));
    tos_value_ = std::make_shared<Integer>(array.size());
}

void FunctionCallVisitor::Visit(AssertStatement* statement) {
    auto result = Accept(statement->expr_);

    if (!GetBoolOrThrow(result)) {
        throw std::runtime_error("Assertion failed.");
    }
}

void FunctionCallVisitor::Visit(IfElseStatement* statement) {
    auto result = Accept(statement->expr_);

    if (GetBoolOrThrow(result)) {
        statement->if_statement_->Accept(this);
    } else {
        statement->else_statement_->Accept(this);
    }
}

void FunctionCallVisitor::Visit(IfStatement* statement) {
    auto result = Accept(statement->expr_);
    if (GetBoolOrThrow(result)) {
        statement->statement_->Accept(this);
    }
}

void FunctionCallVisitor::Visit(LocalVariableDeclarationStatement* statement) {
    statement->variableDeclaration_->Accept(this);
}

void FunctionCallVisitor::Visit(MethodInvocationStatement* statement) {
    statement->methodInvocation_->Accept(this);
}

void FunctionCallVisitor::Visit(PrintlnStatement* statement) {
    auto result = GetIntOrThrow(Accept(statement->expr_));
    std::cout << result << std::endl;
}

void FunctionCallVisitor::Visit(ReturnStatement* statement) {
    if (frame.HasParent()) {
        frame.SetParentReturnValue(Accept(statement->expr_));
    }
    returned_ = true;
}

void FunctionCallVisitor::Visit(ScopeStatements* statement) {
    std::cerr << "Going inside" << std::endl;

    current_layer_ = current_layer_->GetChild(offsets_.top());

    offsets_.push(0);
    frame.AllocScope();
    table_.BeginScope();

    for (const auto& subStatement : statement->statements_) {
        subStatement->Accept(this);
    }

    offsets_.pop();
    size_t index = offsets_.top();

    offsets_.pop();
    offsets_.push(index + 1);

    current_layer_ = current_layer_->GetParent();
    frame.DeallocScope();
    table_.EndScope();
}

void FunctionCallVisitor::Visit(SetLvalueStatement* statement) {
    auto value = Accept(statement->expr_);

    int index = table_.Get(Symbol(statement->lvalue_));
    frame.Set(index, value);
}

void FunctionCallVisitor::Visit(WhileStatement* statement) {
    auto result = Accept(statement->expr_);

    while (GetBoolOrThrow(result)) {
        statement->statement_->Accept(this);
        result = Accept(statement->expr_);
    }
}

void FunctionCallVisitor::SetTree(ScopeLayerTree *tree) {
    tree_ = tree;
}

Frame &FunctionCallVisitor::GetFrame() {
    return frame;
}
