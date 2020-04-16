#ifndef COMPILER_OBJECT_H
#define COMPILER_OBJECT_H

#include <iostream>
#include <memory>

class Object {
public:
    Object() : initialized_(false) {}
    virtual ~Object() = default;

    virtual std::string GetType() const = 0;

    virtual void Set(const std::shared_ptr<Object>& other) {
        is_type_ = other->is_type_;
        initialized_ = other->initialized_;
    };

    void MarkType() {
        is_type_ = true;
    }

    bool IsType() const {
        return is_type_;
    }

protected:
    bool is_type_;
    bool initialized_;
};

#endif //COMPILER_OBJECT_H
