#ifndef COMPILER_IRTEMPLATE_VISITOR_H
#define COMPILER_IRTEMPLATE_VISITOR_H


#include "visitor.h"
#include "../nodes/base_element.h"

namespace IRT {
    template<typename T>
    class IrTemplateVisitor : public Visitor {
    public:
        T Accept(BaseElement* element);
    protected:
        T tos_value_;

    };

}

#endif //COMPILER_IRTEMPLATE_VISITOR_H
