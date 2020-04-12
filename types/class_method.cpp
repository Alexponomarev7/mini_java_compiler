#include "class_method.h"

ClassMethodType::ClassMethodType(std::string returnType
        , std::string id
        , std::vector<Variable> variables) :
        returnType_(std::move(returnType))
        , variables_(std::move(variables))
        , id_(std::move(id))
{}

void ClassMethodType::Set(const std::shared_ptr<Object> &other) {
    auto ptr = dynamic_cast<ClassMethodType*>(other.get());
    returnType_ = ptr->returnType_;
    variables_ = ptr->variables_;
    id_ = ptr->id_;
    Object::Set(other);
}

std::string ClassMethodType::GetType() const {
    return "method";
}

std::string ClassMethodType::GetReturnType() const {
    return returnType_;
}

std::vector<Variable> ClassMethodType::GetVariables() const {
    return variables_;
}

std::string ClassMethodType::GetId() const {
    return id_;
}
