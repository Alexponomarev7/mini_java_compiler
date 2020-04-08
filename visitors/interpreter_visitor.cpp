#include <components/program.h>
#include "interpreter_visitor.h"

InterpreterVisitor::InterpreterVisitor() {}

void InterpreterVisitor::Visit(Program* program) {
    program->main_->Accept(this);
}

void InterpreterVisitor::Visit(MainClass* mainClass) {
    variables_.emplace_back();
    types_.emplace_back();

    for (const auto& statement : mainClass->statements_) {
        statement->Accept(this);
    }

    variables_.pop_back();
    types_.pop_back();
}

void InterpreterVisitor::Visit(Class* classObj) {
    // pass
}

void InterpreterVisitor::Visit(Formal* formal) {
    // pass
}

void InterpreterVisitor::Visit(MethodInvocation* methodInvocation) {
    // pass
}

void InterpreterVisitor::Visit(VariableDeclaration* variableDeclaration) {
    const auto& id = variableDeclaration->id_;

    if (variables_.back().find(id) != variables_.back().end()) {
        throw std::runtime_error("Duplicate variable name.");
    }

    variables_.back()[id] = 0;
    types_.back()[id] = variableDeclaration->type_;
}

void InterpreterVisitor::Visit(MethodDeclaration* methodDeclaration) {
    // pass
}

void InterpreterVisitor::Visit(ArrayMakeExpression* arrayMakeExpression) {
    // pass
}

void InterpreterVisitor::Visit(BinaryExpression* binaryExpression) {
    binaryExpression->leftExpr_->Accept(this);
    auto leftResult = Load_();

    binaryExpression->rightExpr_->Accept(this);
    auto rightResult = Load_();

    auto binary = binaryExpression->binaryOperator_;

    if (binary == "+") {
        assert(leftResult.first == "int");
        assert(rightResult.first == "int");
        SaveInt_(leftResult.second + rightResult.second);
    } else if (binary == "-") {
        assert(leftResult.first == "int");
        assert(rightResult.first == "int");
        SaveInt_(leftResult.second - rightResult.second);
    } else if (binary == "*") {
        assert(leftResult.first == "int");
        assert(rightResult.first == "int");
        SaveInt_(leftResult.second * rightResult.second);
    } else if (binary == "/") {
        assert(leftResult.first == "int");
        assert(rightResult.first == "int");
        SaveInt_(leftResult.second / rightResult.second);
    } else if (binary == "%") {
        assert(leftResult.first == "int");
        assert(rightResult.first == "int");
        SaveInt_(leftResult.second % rightResult.second);
    } else if (binary == ">") {
        assert(leftResult.first == "int");
        assert(rightResult.first == "int");
        SaveBool_(leftResult.second > rightResult.second);
    } else if (binary == "<") {
        assert(leftResult.first == "int");
        assert(rightResult.first == "int");
        SaveBool_(leftResult.second < rightResult.second);
    } else if (binary == "==") {
        assert(leftResult.first == rightResult.first);
        SaveBool_(leftResult.second == rightResult.second);
    } else if (binary == "||") {
        assert(leftResult.first == "bool");
        assert(rightResult.first == "bool");
        SaveBool_(leftResult.second || rightResult.second);
    } else if (binary == "&&") {
        assert(leftResult.first == "bool");
        assert(rightResult.first == "bool");
        SaveBool_(leftResult.second && rightResult.second);
    } else {
        throw std::runtime_error("Unknown binary operator.");
    }
}

void InterpreterVisitor::Visit(InverseExpression* inverseExpression) {
    inverseExpression->expr_->Accept(this);
    auto result = LoadBool_();
    SaveBool_(!result);
}

void InterpreterVisitor::Visit(MethodInvocationExpression* methodInvocationExpression) {
    // pass
}

void InterpreterVisitor::Visit(ObjectMakeExpression* objectMakeExpression) {
    // pass
}

void InterpreterVisitor::Visit(SimpleExpression* simpleExpression) {
    auto value = simpleExpression->value_;

    if (value == "true") {
        SaveBool_(true);
    } else if (value == "false") {
        SaveBool_(false);
    } else if (value == "this") {
        throw std::runtime_error("Unimplemented.");
    } else if (IsNumber_(value)) {
        SaveInt_(std::stoi(value));
    } else {
        for (int i = (int)variables_.size() - 1; i >= 0; i--) {
            if (variables_[i].find(value) != variables_[i].end()) {
                Save_(types_[i][value], variables_[i][value]);
                return;
            }
        }
        throw std::runtime_error("Invalid token.");
    }
}

void InterpreterVisitor::Visit(LengthExpression* lengthExpression) {
    // pass
}

void InterpreterVisitor::Visit(AssertStatement* statement) {
    statement->expr_->Accept(this);
    auto result = LoadBool_();

    if (!result) {
        throw std::runtime_error("Assertion failed.");
    }
}

void InterpreterVisitor::Visit(IfElseStatement* statement) {
    statement->expr_->Accept(this);
    auto result = LoadBool_();

    if (result) {
        statement->if_statement_->Accept(this);
    } else {
        statement->else_statement_->Accept(this);
    }
}

void InterpreterVisitor::Visit(IfStatement* statement) {
    statement->expr_->Accept(this);
    auto result = LoadBool_();

    if (result) {
        statement->statement_->Accept(this);
    }
}

void InterpreterVisitor::Visit(LocalVariableDeclarationStatement* statement) {
    statement->variableDeclaration_->Accept(this);
}

void InterpreterVisitor::Visit(MethodInvocationStatement* statement) {
    // pass
}

void InterpreterVisitor::Visit(PrintlnStatement* statement) {
    statement->expr_->Accept(this);
    auto result = LoadInt_();

    std::cout << result << std::endl;
}

void InterpreterVisitor::Visit(ReturnStatement* statement) {
    statement->expr_->Accept(this);
    auto result = LoadInt_();

    exit(result);
}

void InterpreterVisitor::Visit(ScopeStatements* statement) {
    variables_.emplace_back();
    types_.emplace_back();

    for (const auto& subStatement : statement->statements_) {
        subStatement->Accept(this);
    }

    variables_.pop_back();
    types_.pop_back();
}

void InterpreterVisitor::Visit(SetLvalueStatement* statement) {
    statement->expr_->Accept(this);

    auto result = Load_();
    auto variableName = statement->lvalue_;

    for (int i = (int)variables_.size() - 1; i >= 0; i--) {
        if (variables_[i].find(variableName) != variables_[i].end()) {
            assert(types_[i][variableName] == result.first);
            variables_[i][variableName] = result.second;
            return;
        }
    }
    throw std::runtime_error("No such variable in this scope.");
}

void InterpreterVisitor::Visit(WhileStatement* statement) {
    statement->expr_->Accept(this);
    auto result = LoadBool_();

    while (result) {
        statement->statement_->Accept(this);
        statement->expr_->Accept(this);
        result = LoadBool_();
    }
}

bool InterpreterVisitor::IsNumber_(const std::string& value) {
    return !value.empty() && std::all_of(value.begin(), value.end(), ::isdigit);
}

int InterpreterVisitor::LoadInt_() {
    assert(lastType_ == "int");
    return (int) lastValue_;}

bool InterpreterVisitor::LoadBool_() {
    assert(lastType_ == "boolean");
    return (bool) lastValue_;
}

std::pair<std::string, int> InterpreterVisitor::Load_() {
    return std::make_pair(lastType_, lastValue_);
}

void InterpreterVisitor::SaveInt_(int value) {
    lastType_ = "int";
    lastValue_ = value;
}

void InterpreterVisitor::SaveBool_(bool value) {
    lastType_ = "boolean";
    lastValue_ = (int) value;
}

void InterpreterVisitor::Save_(std::string type, int value) {
    lastType_ = std::move(type);
    lastValue_ = value;
}
