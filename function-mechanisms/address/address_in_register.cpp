#include "address_in_register.h"

#include <irtree/nodes/expressions/temp_expression.h>

namespace IRT {
    Expression *AddressInRegister::ToExpression() {
        return new TempExpression(temp_);
    }
    AddressInRegister::AddressInRegister(const Temporary &temp)
            : temp_(temp) {

    }

}
