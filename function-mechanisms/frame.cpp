//
// Created by Alexey A. Ponomarev on 03.05.2020.
//

#include "frame.h"

Frame::Frame(std::shared_ptr<ClassMethodType> &function) {
    params_.resize(function->GetVariables().size());

    AllocScope();
}

void Frame::SetParams(const std::vector<std::shared_ptr<Object>> &values) {
    if (params_.size() != values.size()) {
        throw std::runtime_error("Mismatched number of arguments");
    }
    params_ = values;
}

size_t Frame::AllocVariable() {
    size_t index = variables_.size();
    variables_.push_back(0);

    return index;
}

void Frame::DeallocScope() {
    size_t new_size = offsets_.top();
    offsets_.pop();

    // TODO(@akhtyamovpavel) - Call destructors
    variables_.resize(new_size);
}

void Frame::AllocScope() {
    offsets_.push(variables_.size());
}

std::shared_ptr<Object> Frame::Get(int index) const {
    if (index >= 0) {
        return variables_.at(index);
    } else {
        return params_.at(-index - 1);
    }
}

void Frame::Set(int index, const std::shared_ptr<Object>& value) {
    if (index >= 0) {
        variables_.at(index) = value;
    } else {
        params_.at(-index - 1) = value;
    }
}

void Frame::SetReturnValue(std::shared_ptr<Object> value) {
    return_value_ = value;
}

void Frame::SetParentFrame(Frame *frame) {
    parent_frame = frame;

}

void Frame::SetParentReturnValue(std::shared_ptr<Object> value) {
    parent_frame->return_value_ = value;
}

bool Frame::HasParent() {
    return parent_frame != nullptr;
}

std::shared_ptr<Object> Frame::GetReturnValue() const {
    return return_value_;
}
