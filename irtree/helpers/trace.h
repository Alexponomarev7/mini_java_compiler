#ifndef COMPILER_TRACE_H
#define COMPILER_TRACE_H

#include <vector>
#include "irtree/helpers/block.h"

namespace IRT {

    class Trace {
    public:
        Trace() = default;

        void Add(Block* block);

        bool CanContinue(Block* block);

        void Accept(Visitor *visitor);

    private:
        std::vector<Block*> blocks_;
    };

}

#endif //COMPILER_TRACE_H
