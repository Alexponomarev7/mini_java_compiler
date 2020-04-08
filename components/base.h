#ifndef COMPILER_BASE_H
#define COMPILER_BASE_H

#include "visitors/visitor.h"
#include "visitors/print_visitor.h"

#include <vector>
#include <string>
#include <variant>

class BaseElement {
public:
    virtual void Accept(Visitor* visitor) = 0;
    virtual ~BaseElement() = default;
};

#endif //COMPILER_BASE_H
