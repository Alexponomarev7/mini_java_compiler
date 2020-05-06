#include "types.h"

Object* GetType(const Type& type) {
    throw std::runtime_error("deprecated");
}


void EqualTypesOrThrow(std::shared_ptr<Object> lvalue, std::shared_ptr<Object> rvalue) {
    if (lvalue->GetType() != rvalue->GetType()) {
        throw std::runtime_error("Incorrect types.");
    }
}
