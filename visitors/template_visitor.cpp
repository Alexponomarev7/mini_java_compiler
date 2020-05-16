#include <irtree/tree_wrapper/subtree_wrapper.h>
#include "template_visitor.h"


template<typename T>
T TemplateVisitor<T>::Accept(BaseElement* element) {
    element->Accept(this);
    return tos_value_;
}

template IRT::SubtreeWrapper* TemplateVisitor<IRT::SubtreeWrapper*>::Accept(BaseElement* element);

template std::shared_ptr<Object> TemplateVisitor<std::shared_ptr<Object>>::Accept(BaseElement* element);

