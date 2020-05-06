#include "location.h"

Location* Location::GetInstance() {
    if (state_ == nullptr) {
        state_ = new Location();
    }

    return state_;
}

yy::location Location::GetLocation() const {
    return loc_;
}

yy::location Location::SetLocation(yy::location loc) {
    loc_ = loc;
}

Location* Location::state_ = nullptr;
