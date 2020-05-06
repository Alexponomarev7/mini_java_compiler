#ifndef COMPILER_CLASST_H
#define COMPILER_CLASST_H

#include "object.h"
#include "help.h"
#include <vector>

class ClassType : public Object {
public:
    ClassType() = default;
    ClassType(std::string id, std::vector<Variable> variables);

    void Set(const std::shared_ptr<Object>& other) override;
    std::string GetType() const override;

    std::vector<Variable> GetVariables() const;
    std::string GetId() const;

private:
    std::vector<Variable> variables_;
    std::string id_;
};

const ClassType* GetClassOrThrow(const std::shared_ptr<Object>& object);

#endif //COMPILER_CLASS_H
