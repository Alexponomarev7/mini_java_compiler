#ifndef COMPILER_HELP_H
#define COMPILER_HELP_H

#include <vector>
#include <string>

struct Variable {
    std::string type;
    std::string name;

    Variable(std::string type, std::string name) : type(std::move(type)), name(std::move(name)) {}
};

struct Method {
    std::string returnType;
    std::string name;
    std::vector<Variable> variables;
};

#endif //COMPILER_HELP_H
