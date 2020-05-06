#include "scope_layer_tree.h"

ScopeLayerTree::ScopeLayerTree(ScopeLayer* root) : root_(root) {
    type_layer_ = new ScopeLayer();
}

void ScopeLayerTree::PrintTree(const std::string& filename) {
    stream_ = std::ofstream(filename);

    root_->PrintLayer(stream_, 0);

    stream_.close();
}

ScopeLayerTree::ScopeLayerTree(const ScopeLayerTree &other) {
    root_ = other.root_;
    layer_mapping_ = other.layer_mapping_;
    type_layer_ = other.type_layer_;
}

void ScopeLayerTree::AddMapping(const Symbol& name, ScopeLayer *layer) {
    if (layer_mapping_.find(name) != layer_mapping_.end()) {
        throw std::runtime_error("Function has already been declared");
    }

    layer_mapping_[name] = layer;
}

ScopeLayer *ScopeLayerTree::GetFunctionScopeByName(const Symbol& name) {
    if (layer_mapping_.find(name) == layer_mapping_.end()) {
        throw std::runtime_error("No such function " + name.GetName());
    }
    return layer_mapping_[name];
}

std::shared_ptr<Object> ScopeLayerTree::Get(const Symbol& symbol) {
    return root_->Get(symbol);
}

void ScopeLayerTree::AddType(Type name, std::shared_ptr<Object> type) {
    type_layer_->DeclareVariable(name, type);
}


std::shared_ptr<Object> ScopeLayerTree::GetType(Type type) {
    return type_layer_->Get(type);
}

