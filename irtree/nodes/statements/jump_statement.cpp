//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#include "jump_statement.h"

namespace IRT {

    void JumpStatement::Accept(Visitor *visitor) {
        visitor->Visit(this);

    }
    JumpStatement::JumpStatement(Label label): label_(label) {

    }
}
