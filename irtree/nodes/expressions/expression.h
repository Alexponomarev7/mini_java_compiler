#ifndef COMPILER_IRTREE_EXPRESSION_H
#define COMPILER_IRTREE_EXPRESSION_H

#include "irtree/nodes/base_element.h"

namespace IRT {

    class Expression : public BaseElement {
    public:
        virtual ~Expression() = default;
    };
}

#endif //COMPILER_EXPRESSION_H
