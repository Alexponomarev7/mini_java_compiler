#ifndef COMPILER_CONST_EXPRESSION_H
#define COMPILER_CONST_EXPRESSION_H


#include "expression.h"

namespace IRT {

    class ConstExpression : public Expression {
    public:
        explicit ConstExpression(int value);
        ~ConstExpression() final = default;
        int Value() const;

        void Accept(Visitor *visitor) override;
    private:
        int value_;
    };

}

#endif //COMPILER_CONST_EXPRESSION_H
