#ifndef IRTREE_BASE_ELEMENT_H
#define IRTREE_BASE_ELEMENT_H

#include "irtree/visitors/visitor.h"

namespace IRT {

    class BaseElement {
    public:
        virtual ~BaseElement() = default;
        virtual void Accept(Visitor* visitor) = 0;
    };
}

#endif //COMPILER_BASE_ELEMENT_H
