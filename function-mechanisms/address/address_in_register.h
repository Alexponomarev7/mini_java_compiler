#ifndef COMPILER_ADDRESS_IN_REGISTER_H
#define COMPILER_ADDRESS_IN_REGISTER_H

#include <irtree/generators/temporary.h>
#include "address.h"

namespace IRT {

    class AddressInRegister : public Address {
    public:
        AddressInRegister(const Temporary& temp);
        Expression *ToExpression() override;
    private:
        Temporary temp_;
    };

}

#endif //COMPILER_ADDRESS_IN_REGISTER_H
