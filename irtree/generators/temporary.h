//
// Created by Alexey A. Ponomarev on 06.05.2020.
//

#ifndef COMPILER_TEMPORARY_H
#define COMPILER_TEMPORARY_H

#include <string>

namespace IRT {
    class Temporary {
    public:
        Temporary();
        explicit Temporary(const std::string& name);
        std::string ToString() const;
    private:
        std::string name_;
        static int counter_;
    };

}

#endif //COMPILER_TEMPORARY_H
