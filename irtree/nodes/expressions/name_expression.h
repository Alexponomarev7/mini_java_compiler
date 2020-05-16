#include "expression.h"
#include "irtree/generators/label.h"

namespace IRT {
    class NameExpression : public Expression {
    public:
        NameExpression(Label label);
        void Accept(Visitor *visitor) override;
        Label label_;
    };

}
