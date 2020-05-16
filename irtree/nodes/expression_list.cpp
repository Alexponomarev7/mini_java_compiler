#include "expression_list.h"

namespace IRT {
    void ExpressionList::Accept(Visitor *visitor) {
        visitor->Visit(this);
    }

    void ExpressionList::Add(Expression *expression) {
        expressions_.push_back(expression);
    }
}
