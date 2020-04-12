#ifndef COMPILER_BOOLEAN_H
#define COMPILER_BOOLEAN_H

#include "object.h"

class Boolean : public Object {
public:
    Boolean();

    explicit Boolean(bool value);
    void Set(const std::shared_ptr<Object>& other) override;
    std::string GetType() const override;
    bool Value();

private:
    bool value_;
};

bool GetBoolOrThrow(const std::shared_ptr<Object>& object);

#endif //COMPILER_BOOLEAN_H
