#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include "class.h"
#include "main_class.h"

#include <vector>

class Program : public BaseElement {
public:
    Program(MainClass* main, std::vector<Class*> classes) :
        main_(main)
        , classes_(std::move(classes))
    {}

    void Accept(Visitor* visitor) override {
        auto current_location = Location::GetInstance()->GetLocation();
        Location::GetInstance()->SetLocation(this->GetLocation());

        visitor->Visit(this);

        Location::GetInstance()->SetLocation(current_location);
    }

private:
    MainClass* main_;
    std::vector<Class*> classes_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
    friend class FunctionCallVisitor;
};

#endif //COMPILER_PROGRAM_H
