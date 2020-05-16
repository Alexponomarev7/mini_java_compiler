#ifndef COMPILER_IRTREE_STATEMENT_H
#define COMPILER_IRTREE_STATEMENT_H

#include "irtree/nodes/base_element.h"

namespace IRT {

    class Statement : public BaseElement {
    public:
        virtual ~Statement() = default;
    };
}

#endif //COMPILER_STATEMENT_H
