#include "integer.h"

Integer::Integer() : Object(), value_(0) {
}

Integer::Integer(int value) :
        value_(value)
{
    initialized_ = true;
}

void Integer::Set(const std::shared_ptr<Object>& other) {
    auto ptr = dynamic_cast<Integer*>(other.get());
    value_ = ptr->Value();
}

int Integer::Value() {
    return value_;
}


int GetIntOrThrow(const std::shared_ptr<Object>& object) {
    auto ptr = dynamic_cast<Integer*>(object.get());
    return ptr->Value();
}
