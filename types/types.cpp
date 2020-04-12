#include "types.h"

Object* GetType(const Type& type) {
    if (type == INT_TYPE) {
        return new Integer();
    } else if (type == BOOL_TYPE) {
        return new Boolean();
    } else if (type == "class") {
        return new ClassType();
    } else if (type == "method") {
        return new ClassMethodType();
    }
    throw std::runtime_error("No such type.");
}


void EqualTypesOrThrow(std::shared_ptr<Object> lvalue, std::shared_ptr<Object> rvalue) {
    if (lvalue->GetType() != rvalue->GetType()) {
        throw std::runtime_error("Incorrect types.");
    }
}
