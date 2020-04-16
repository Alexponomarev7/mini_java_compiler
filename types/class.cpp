#include "class.h"


ClassType::ClassType(std::string id, std::vector<Variable> variables, std::vector<Method> methods) :
    variables_(std::move(variables))
    , methods_(std::move(methods))
    , id_(std::move(id))
{}

std::vector<Variable> ClassType::GetVariables() const {
    return variables_;
}

std::vector<Method> ClassType::GetMethods() const {
    return methods_;
}

std::string ClassType::GetId() const {
    return id_;
}

bool ClassType::HasMethod(std::string name) const {
    for (const auto& method : methods_) {
        if (method.name == name) {
            return true;
        }
    }

    return false;
}

void ClassType::Set(const std::shared_ptr<Object>& other) {
    auto ptr = dynamic_cast<ClassType*>(other.get());
    variables_ = ptr->GetVariables();
    methods_ = ptr->GetMethods();
    Object::Set(other);
}

std::string ClassType::GetType() const {
    return "class " + id_;
}

const ClassType* GetClassOrThrow(const std::shared_ptr<Object>& object) {
    auto ptr = dynamic_cast<ClassType*>(object.get());
    return ptr;
}