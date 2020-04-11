#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H

#include "class.h"
#include "main_class.h"

#include <vector>

class Program : BaseElement {
public:
    Program(MainClass* main, std::vector<Class*> classes) :
        main_(main)
        , classes_(std::move(classes))
    {}

    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }

private:
    MainClass* main_;
    std::vector<Class*> classes_;

    friend class PrintVisitor;
    friend class InterpreterVisitor;
    friend class SymbolTreeVisitor;
};

#endif //COMPILER_PROGRAM_H
