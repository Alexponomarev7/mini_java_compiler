#include "boolean.h"

Boolean::Boolean() : Object(), value_(false) {
}

Boolean::Boolean(bool value) :
        value_(value)
{
    initialized_ = true;
}

void Boolean::Set(const std::shared_ptr<Object>& other) {
    auto ptr = dynamic_cast<Boolean*>(other.get());
    value_ = ptr->Value();
}

bool Boolean::Value() {
    return value_;
}

bool GetBoolOrThrow(const std::shared_ptr<Object>& object) {
    auto ptr = dynamic_cast<Boolean*>(object.get());
    return ptr->Value();
}