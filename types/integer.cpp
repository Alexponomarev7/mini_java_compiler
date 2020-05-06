#include "integer.h"

Integer::Integer() {
    initialized_ = false;
}

Integer::Integer(int value) :
        value_(value)
{
    is_type_ = false;
    initialized_ = true;
}

void Integer::Set(const std::shared_ptr<Object>& other) {
    auto ptr = dynamic_cast<Integer*>(other.get());
    value_ = ptr->Value();
    Object::Set(other);
}

std::string Integer::GetType() const {
    return "int";
}

int Integer::Value() {
    return value_;
}


int GetIntOrThrow(const std::shared_ptr<Object>& object) {
    auto ptr = dynamic_cast<Integer*>(object.get());

    if (ptr == nullptr) {
        throw runtime_error_location("cannot be cast to the type Int");
    }

    return ptr->Value();
}
