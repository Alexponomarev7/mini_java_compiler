//
// Created by Alexey A. Ponomarev on 11.04.2020.
//

#ifndef COMPILER_CLASS_METHOD_H
#define COMPILER_CLASS_METHOD_H

#include "object.h"

class ClassMethod : public Object {
public:
    ClassMethod();

    explicit ClassMethod(std::string returnType, std::vector<std::string> types);
    void Set(const std::shared_ptr<Object>& other) override;
    bool Value();

private:
    bool value_;
};

bool GetBoolOrThrow(const std::shared_ptr<Object>& object);


#endif //COMPILER_CLASS_METHOD_H
