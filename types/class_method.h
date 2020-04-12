//
// Created by Alexey A. Ponomarev on 11.04.2020.
//

#ifndef COMPILER_CLASS_METHOD_H
#define COMPILER_CLASS_METHOD_H

#include "object.h"
#include "help.h"

class ClassMethodType : public Object {
public:
    ClassMethodType() = default;

    ClassMethodType(std::string returnType, std::string id, std::vector<Variable> variables);
    void Set(const std::shared_ptr<Object>& other) override;
    std::string GetType() const override;

    std::string GetReturnType() const;
    std::string GetId() const;
    std::vector<Variable> GetVariables() const;

private:
    std::string returnType_;
    std::vector<Variable> variables_;
    std::string id_;
};

#endif //COMPILER_CLASS_METHOD_H
