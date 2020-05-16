#include "frame_emulator.h"

FrameEmulator::FrameEmulator(std::shared_ptr<ClassMethodType> function) {
    params_.resize(function->GetVariables().size());

    AllocScope();
}

void FrameEmulator::SetParams(const std::vector<std::shared_ptr<Object>> &values) {
    if (params_.size() != values.size()) {
        throw std::runtime_error("Mismatched number of arguments");
    }
    params_ = values;
}

size_t FrameEmulator::AllocVariable(std::shared_ptr<Object> object) {
    size_t index = variables_.size();
    variables_.push_back(object);

    return index;
}

void FrameEmulator::DeallocScope() {
    size_t new_size = offsets_.top();
    offsets_.pop();

    // TODO(@akhtyamovpavel) - Call destructors
    variables_.resize(new_size);
}

void FrameEmulator::AllocScope() {
    offsets_.push(variables_.size());
}

std::shared_ptr<Object> FrameEmulator::Get(int index) const {
    if (index >= 0) {
        return variables_.at(index);
    } else {
        return params_.at(-index - 1);
    }
}

void FrameEmulator::SetSafe(std::shared_ptr<Object>& itemInMemory, const std::shared_ptr<Object>& value) {
    //std::cerr << " " << value->GetType() << std::endl;
    EqualTypesOrThrow(itemInMemory, value);
    itemInMemory = value;
}

void FrameEmulator::Set(int index, std::shared_ptr<Object> value) {
    if (index >= 0) {
        SetSafe(variables_.at(index), value);
    } else {
        SetSafe(params_.at(-index - 1), value);
    }
}

void FrameEmulator::SetReturnValue(int value) {
    return_value_ = value;
}

void FrameEmulator::SetParentFrame(FrameEmulator *frame) {
    parent_frame = frame;

}

void FrameEmulator::SetParentReturnValue(int value) {
    parent_frame->return_value_ = value;

}

bool FrameEmulator::HasParent() {
    return parent_frame != nullptr;
}

int FrameEmulator::GetReturnValue() const {
    return return_value_;
}
