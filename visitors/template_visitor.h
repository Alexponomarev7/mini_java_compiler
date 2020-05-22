#ifndef COMPILER_TEMPLATE_VISITOR_H
#define COMPILER_TEMPLATE_VISITOR_H

#include "components/base.h"
#include "components/statement/statement.h"
#include "components/expression/expression.h"
#include "visitor.h"

#include "types/types.h"

template<typename T>
class TemplateVisitor : public Visitor {
public:
    T Accept(BaseElement* element);
protected:
    T tos_value_;
};


#endif //COMPILER_IRTEMPLATE_VISITOR_H
