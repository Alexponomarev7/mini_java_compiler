#ifndef COMPILER_LABEL_H
#define COMPILER_LABEL_H

#include <string>

namespace IRT {
    class Label {
    public:
        Label();
        explicit Label(std::string label);

        std::string ToString() const;

    private:
        std::string label_;
        static int counter_;
    };
}


#endif //COMPILER_LABEL_H