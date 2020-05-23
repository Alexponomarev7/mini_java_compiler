#include "trace.h"

namespace IRT {
    void Trace::Add(Block *block) {
        if (!blocks_.empty()) {
            assert(blocks_.back()->OutputLabel().ToString() == block->InputLabel().ToString());
        }

        blocks_.push_back(block);
    }

    bool Trace::CanContinue(Block *block) {
        if (blocks_.empty()) {
            return true;
        }

        return blocks_.back()->OutputLabel().ToString() == block->InputLabel().ToString();
    }

    void Trace::Accept(Visitor *visitor) {
        for (auto block : blocks_) {
            block->Accept(visitor);
        }
    }
}