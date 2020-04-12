#include "boolean.h"

Boolean::Boolean() : value_(false) {
    initialized_ = false;
}

Boolean::Boolean(bool value) :
        value_(value)
{
    initialized_ = true;
}

void Boolean::Set(const std::shared_ptr<Object>& other) {
    auto ptr = dynamic_cast<Boolean*>(other.get());
    value_ = ptr->Value();
    Object::Set(other);
}

std::string Boolean::GetType() const {
    return "bool";
}

bool Boolean::Value() {
    return value_;
}

bool GetBoolOrThrow(const std::shared_ptr<Object>& object) {
    auto ptr = dynamic_cast<Boolean*>(object.get());
    return ptr->Value();
}