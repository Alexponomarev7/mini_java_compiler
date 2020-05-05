#include "scope_layer.h"

#include <iostream>
#include <components/declaration/method_declaration.h>
#include <components/formal.h>

ScopeLayer::ScopeLayer(ScopeLayer* parent): parent_(parent) {
    std::cerr << "Constructor called" << std::endl;
    std::cerr << "End contstructor called" << std::endl;

    parent_->AddChild(this);

}

void ScopeLayer::AttachParent() {

}

ScopeLayer::ScopeLayer(): parent_(nullptr) {}


void ScopeLayer::DeclareVariable(Symbol symbol, std::shared_ptr<Object> type) {
    if (values_.find(symbol) != values_.end()) {
        throw std::runtime_error("Variable has declared");
    }

    std::cerr << "Variable " + symbol.GetName() << " declared" << std::endl;

    values_[symbol] = type;
    offsets_[symbol] = symbols_.size();
    symbols_.push_back(symbol);
}

void ScopeLayer::DeclareFunction(Symbol symbol, MethodDeclaration *function) {
    if (values_.find(symbol) != values_.end()) {
        throw std::runtime_error("Function has declared");
    }

    std::cerr << "Method " + symbol.GetName() << " declared" << std::endl;

    std::vector<Variable> variables;
    for (Formal* formal : function->formals_) {
        variables.emplace_back(formal->type_, formal->id_);
    }

    values_[symbol] = std::make_shared<ClassMethodType>(function->type_, function->id_, variables);
}

void ScopeLayer::Put(Symbol symbol, std::shared_ptr<Object> value) {
    ScopeLayer* current_layer = this;

    while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
        current_layer = current_layer->parent_;
    }

    if (current_layer->Has(symbol)) {
        current_layer->values_.find(symbol)->second->Set(value);
    } else {
        throw std::runtime_error("Variable " + symbol.GetName() + " not declared");
    }

}

bool ScopeLayer::Has(Symbol symbol) {
    return values_.find(symbol) != values_.end();
}


std::shared_ptr<Object> ScopeLayer::Get(Symbol symbol) {
    ScopeLayer* current_layer = this;

    while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
        current_layer = current_layer->parent_;
    }

    if (current_layer->Has(symbol)) {
        return current_layer->values_.find(symbol)->second;
    } else {
        throw std::runtime_error("Variable " + symbol.GetName() + " not declared");
    }
}

ScopeLayer* ScopeLayer::GetChild(size_t index) {
    //std::cout << "Children of scope: " << children_.size() << std::endl;
    return children_[index];
}

void ScopeLayer::AddChild(ScopeLayer* child) {
    children_.push_back(child);
}

ScopeLayer* ScopeLayer::GetParent() const {
    return parent_;
}

ScopeLayer::~ScopeLayer() {
    for (ScopeLayer* layer: children_) {
        delete layer;
    }
}

void ScopeLayer::PrintLayer(std::ostream &stream, int num_tabs) const {

    for (auto symbol : symbols_) {
        for (int i = 0; i < num_tabs; ++i) {
            stream << "\t";
        }
        stream << symbol.GetName() << std::endl;
    }
    for (ScopeLayer* layer : children_) {
        layer->PrintLayer(stream, num_tabs + 1);
    }
}
