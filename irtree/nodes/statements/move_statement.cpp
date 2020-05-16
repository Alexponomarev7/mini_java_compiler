#include "move_statement.h"

namespace IRT {
    void MoveStatement::Accept(IRT::Visitor *visitor) {
        visitor->Visit(this);
    }
    MoveStatement::MoveStatement(
            Expression *source,
            Expression *target
    ): source_(source), target_(target) {

    }

}
