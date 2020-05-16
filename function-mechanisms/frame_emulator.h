#ifndef COMPILER_FRAME_EMULATOR_H
#define COMPILER_FRAME_EMULATOR_H

#include <stack>
#include "types/class_method.h"
#include "types/types.h"

#include <memory>
#include <types/object.h>

class FrameEmulator {
public:
    explicit FrameEmulator(std::shared_ptr<ClassMethodType> function);
    void SetParams(const std::vector<std::shared_ptr<Object>>& values);

    size_t AllocVariable(std::shared_ptr<Object> object);

    void DeallocScope();
    void AllocScope();

    std::shared_ptr<Object> Get(int index) const;

    void Set(int index, std::shared_ptr<Object> value);

    void SetParentFrame(FrameEmulator* frame);

    int GetReturnValue() const;

    void SetParentReturnValue(int value);

    bool HasParent();

private:
    std::stack<int> offsets_;
    std::vector<std::shared_ptr<Object>> params_;
    std::vector<std::shared_ptr<Object>> variables_;

    static void SetSafe(std::shared_ptr<Object>& itemInMemory, const std::shared_ptr<Object>& value);

    int return_value_ = 0;

    void SetReturnValue(int value);

    FrameEmulator* parent_frame = nullptr;

};

#endif //COMPILER_FRAME_EMULATOR_H
