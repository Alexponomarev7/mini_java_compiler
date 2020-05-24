#ifndef COMPILER_REGISTRY_H
#define COMPILER_REGISTRY_H

#include <string>

namespace IRT {
    class Registry {
    public:
        Registry();
        explicit Registry(std::string registry);

        std::string ToString() const;

        static const std::string FRAME_POINTER_REG;

    private:
        std::string registry_;
        static int counter_;
    };

    enum Reg {
        FramePointer
    };

    std::string ToASM(Reg reg);
}

#endif //COMPILER_REGISTRY_H
