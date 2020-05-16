#ifndef COMPILER_ADDRESS_IN_FRAME_H
#define COMPILER_ADDRESS_IN_FRAME_H

#include "address.h"

namespace IRT {

    class AddressInFrame: public Address {
    public:
        AddressInFrame(
                Address* frame_address,
                int offset
        );
        ~AddressInFrame() = default;
        Expression *ToExpression() override;
    private:
        Address* frame_address_;
        int offset_;

    };

}

#endif //COMPILER_ADDRESS_IN_FRAME_H
