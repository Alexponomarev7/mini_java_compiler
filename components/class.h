#ifndef COMPILER_CLASS_H
#define COMPILER_CLASS_H

#include "base.h"
#include "components.h"

class Class : public BaseElement {
public:
    Class(Identifier id, Extension extension, std::vector<Declaration*> declarations) :
        id_(std::move(id))
        , extension_(std::move(extension))
        , declarations_(std::move(declarations))
    {}

    void Accept(Visitor* visitor) {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    Identifier id_;
    Extension extension_;
    std::vector<Declaration*> declarations_;

    friend class PrintVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_CLASS_H
