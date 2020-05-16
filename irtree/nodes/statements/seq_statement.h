#ifndef COMPILER_SEQ_STATEMENT_H
#define COMPILER_SEQ_STATEMENT_H

#include "statement.h"

namespace IRT {
    class SeqStatement : public Statement {
    public:
        SeqStatement(Statement* first, Statement* second);
        void Accept(Visitor *visitor) override;
        Statement* first_statement_;
        Statement* second_statement_;
    };

}

#endif //COMPILER_SEQ_STATEMENT_H
