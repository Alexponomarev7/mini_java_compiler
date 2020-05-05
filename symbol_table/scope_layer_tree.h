#ifndef COMPILER_SCOPE_LAYER_TREE_H
#define COMPILER_SCOPE_LAYER_TREE_H


#include "scope_layer.h"
#include <fstream>

class ScopeLayerTree {
public:
    explicit ScopeLayerTree(ScopeLayer* root);
    ScopeLayerTree(const ScopeLayerTree &other);
    void PrintTree(const std::string& filename);

    std::shared_ptr<Object> Get(const Symbol& symbol);
    ~ScopeLayerTree() = default;

    /**
     * Adds mapping from named scope for fast access
     * @param name - name of layer - function name
     * @param layer - scope layer to use
     */
    void AddMapping(const Symbol& name, ScopeLayer* layer);

    /**
     * Get function by name
     * @param name
     * @return Function scope
     */
    ScopeLayer* GetFunctionScopeByName(const Symbol& name);

public:
    ScopeLayer* root_;

private:
    std::ofstream stream_;
    std::unordered_map<Symbol, ScopeLayer*> layer_mapping_;
};


#endif //COMPILER_SCOPE_LAYER_TREE_H
