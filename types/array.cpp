#include "array.h"

Array::Array(std::shared_ptr<Object>& type) : type_(type), values_() {
    initialized_ = false;
}

Array::Array(std::shared_ptr<Object>& type, int length) :
    values_(length)
    , type_(type) {
    initialized_ = true;
}

void Array::Set(const std::shared_ptr<Object> &other) {
    auto ptr = dynamic_cast<Array*>(other.get());
    assert(type_->GetType() == ptr->type_->GetType());
    values_ = ptr->values_;
    Object::Set(other);
}

std::string Array::GetType() const {
    return "array " + type_->GetType();
}

std::vector<std::shared_ptr<Object>> Array::Value() {
    return values_;
}

std::vector<std::shared_ptr<Object>> GetArrayOrThrow(const std::shared_ptr<Object>& object) {
    auto ptr = dynamic_cast<Array*>(object.get());

    if (ptr == nullptr) {
        throw runtime_error_location("cannot be cast to the type Array");
    }

    return ptr->Value();
}

bool IsArrayType(const std::string& name) {
    return name.length() > 2 && name[name.length() - 2] == '[' && name[name.length() - 1] == ']';
}

std::string GetBasicType(const std::string& name) {
    std::string basic;
    basic.reserve(name.size() - 2);

    for (size_t i = 0; i < name.size() - 2; ++i) {
        basic.push_back(name[i]);
    }
    return basic;
}