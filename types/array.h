#ifndef COMPILER_ARRAY_H
#define COMPILER_ARRAY_H

#include "object.h"
#include <vector>

class Array : public Object {
public:
    Array(std::shared_ptr<Object>& type);

    explicit Array(std::shared_ptr<Object>& type, int length);
    void Set(const std::shared_ptr<Object>& other) override;
    std::vector<std::shared_ptr<Object>> Value();
    std::string GetType() const override;

private:
    std::shared_ptr<Object> type_;
    std::vector<std::shared_ptr<Object>> values_;
};

std::vector<std::shared_ptr<Object>> GetArrayOrThrow(const std::shared_ptr<Object>& object);

bool IsArrayType(const std::string& name);

std::string GetBasicType(const std::string& name);

#endif //COMPILER_ARRAY_H
