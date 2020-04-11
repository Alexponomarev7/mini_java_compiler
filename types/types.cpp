#include "types.h"

Object* GetType(const Type& type) {
    if (type == INT_TYPE) {
        return new Integer();
    } else if (type == BOOL_TYPE) {
        return new Boolean();
    }
}

