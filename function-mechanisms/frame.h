//
// Created by Alexey A. Ponomarev on 03.05.2020.
//

#ifndef COMPILER_FRAME_H
#define COMPILER_FRAME_H


#include "types/class_method.h"
#include "types/types.h"
#include <stack>
#include <memory>

class Frame {
public:
    explicit Frame(std::shared_ptr<ClassMethodType> &function);
    void SetParams(const std::vector<std::shared_ptr<Object>>& values);

    size_t AllocVariable(std::shared_ptr<Object> object);

    void DeallocScope();
    void AllocScope();

    std::shared_ptr<Object> Get(int index) const;

    void Set(int index, const std::shared_ptr<Object>& value);

    void SetParentFrame(Frame* frame);

    std::shared_ptr<Object> GetReturnValue() const;

    void SetParentReturnValue(std::shared_ptr<Object> value);

    bool HasParent();

private:
    std::stack<int> offsets_;
    std::vector<std::shared_ptr<Object>> params_;
    std::vector<std::shared_ptr<Object>> variables_;

    static void SetSafe(std::shared_ptr<Object>& itemInMemory, const std::shared_ptr<Object>& value);

    std::shared_ptr<Object> return_value_ = nullptr;

    void SetReturnValue(std::shared_ptr<Object> value);

    Frame* parent_frame = nullptr;

};


#endif //COMPILER_FRAME_H
