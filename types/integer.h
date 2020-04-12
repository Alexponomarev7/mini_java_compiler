#ifndef COMPILER_INTEGER_H
#define COMPILER_INTEGER_H

#include "object.h"

class Integer : public Object {
public:
    Integer();

    explicit Integer(int value);
    void Set(const std::shared_ptr<Object>& other) override;
    std::string GetType() const override;

    int Value();

private:
    int value_;
};

int GetIntOrThrow(const std::shared_ptr<Object>& object);

#endif //COMPILER_INTEGER_H
