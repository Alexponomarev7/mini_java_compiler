#ifndef COMPILER_STATEMENT_H
#define COMPILER_STATEMENT_H

#include "components/base.h"

class Statement : BaseElement {
    virtual void Accept(Visitor* visitor) = 0;
};

#endif //COMPILER_STATEMENT_H
