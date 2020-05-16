#ifndef COMPILER_EXPRESSION_LIST_H
#define COMPILER_EXPRESSION_LIST_H

#include <vector>
#include "base_element.h"

namespace IRT {
    class Expression;

    class ExpressionList : public BaseElement {
    public:
        ExpressionList() = default;

        void Add(Expression* expression);
        void Accept(Visitor *visitor) override;

        std::vector<Expression*> expressions_;
    };
}


#endif //COMPILER_EXPRESSION_LIST_H
