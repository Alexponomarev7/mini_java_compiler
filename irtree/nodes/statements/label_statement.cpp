//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#include "label_statement.h"

namespace IRT {

    void LabelStatement::Accept(Visitor *visitor) {
        visitor->Visit(this);

    }
    LabelStatement::LabelStatement(IRT::Label label): label_(label) {

    }
}
