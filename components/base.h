#ifndef COMPILER_BASE_H
#define COMPILER_BASE_H

#include "visitors/visitor.h"
#include "parser/location.hh"
#include "location/location.h"

#include <vector>
#include <string>
#include <variant>

class BaseElement {
public:
    virtual void Accept(Visitor* visitor) = 0;
    virtual ~BaseElement() = default;

    void SetLocation(yy::location loc) {
        loc_ = loc;
    }

    void SetLocation(yy::position begin, yy::position end) {
        loc_ = yy::location(begin, end);
    }

    yy::location GetLocation() {
        return loc_;
    }

    yy::position GetBegin() {
        return loc_.begin;
    }

    yy::position GetEnd() {
        return loc_.end;
    }

private:
    yy::location loc_;
};

#endif //COMPILER_BASE_H
