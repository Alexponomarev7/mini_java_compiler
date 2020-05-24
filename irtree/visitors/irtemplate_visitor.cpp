#include "irtemplate_visitor.h"
#include "visitor_struct.h"

namespace IRT {
    template<typename T>
    T IrTemplateVisitor<T>::Accept(BaseElement * element) {
        element->Accept(this);
        return tos_value_;
    }

    template int IrTemplateVisitor<int>::Accept(BaseElement* element);
    template IrtStorage IrTemplateVisitor<IrtStorage>::Accept(IRT::BaseElement *element);
    template Registry IrTemplateVisitor<Registry>::Accept(BaseElement *element);
}
