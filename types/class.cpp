#include "class.h"


ClassType::ClassType(std::string id, std::vector<Variable> variables) :
    variables_(std::move(variables))
    , id_(std::move(id))
{}

std::vector<Variable> ClassType::GetVariables() const {
    return variables_;
}

std::string ClassType::GetId() const {
    return id_;
}

void ClassType::Set(const std::shared_ptr<Object>& other) {
    auto ptr = dynamic_cast<ClassType*>(other.get());
    variables_ = ptr->GetVariables();
    Object::Set(other);
}

std::string ClassType::GetType() const {
    return "class " + id_;
}

const ClassType* GetClassOrThrow(const std::shared_ptr<Object>& object) {
    auto ptr = dynamic_cast<ClassType*>(object.get());
    return ptr;
}