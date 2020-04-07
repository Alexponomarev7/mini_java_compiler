#ifndef COMPILER_CLASS_H
#define COMPILER_CLASS_H

#include "base.h"
#include "components.h"

class Class : BaseElement {
public:
    Class(Identifier id, Extension extension, std::vector<Declaration*> declarations) :
        id_(std::move(id))
        , extension_(std::move(extension))
        , declarations_(std::move(declarations))
    {}

    void Accept(Visitor* visitor) {
        visitor->Visit(this);
    }

private:
    Identifier id_;
    Extension extension_;
    std::vector<Declaration*> declarations_;
};

#endif //COMPILER_CLASS_H
