#ifndef COMPILER_OBJECT_H
#define COMPILER_OBJECT_H

#include <iostream>

class Object {
public:
    Object() : initialized_(false) {}
    virtual ~Object() = default;

    virtual void Set(const std::shared_ptr<Object>& other) = 0;

protected:
    bool initialized_;
};

#endif //COMPILER_OBJECT_H
