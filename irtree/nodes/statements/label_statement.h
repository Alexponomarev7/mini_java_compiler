//
// Created by Alexey A. Ponomarev on 11.05.2020.
//

#ifndef COMPILER_LABEL_STATEMENT_H
#define COMPILER_LABEL_STATEMENT_H

#include "statement.h"
#include "irtree/generators/label.h"

namespace IRT {

    class LabelStatement : public Statement {
    public:
        explicit LabelStatement(IRT::Label label);
        void Accept(Visitor *visitor) override;
        Label label_;
    };

}

#endif //COMPILER_LABEL_STATEMENT_H
