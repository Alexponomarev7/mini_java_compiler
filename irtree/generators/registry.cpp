#include "registry.h"

namespace IRT {
    Registry::Registry() : registry_("R" + std::to_string(counter_++)) {
    }

    Registry::Registry(std::string registry): registry_(std::move(registry)) {

    }

    std::string Registry::ToString() const {
        return registry_;
    }

    int Registry::counter_ = 0;

    std::string ToASM(Reg reg) {
        switch (reg) {
            case Reg::FramePointer:
                return "ebp";
            default:
                assert(0);
        }
    }

}