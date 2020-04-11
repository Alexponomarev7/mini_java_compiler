#ifndef COMPILER_SCOPE_LAYER_TREE_H
#define COMPILER_SCOPE_LAYER_TREE_H


#include "scope_layer.h"

class ScopeLayerTree {
public:
    explicit ScopeLayerTree(ScopeLayer* root);
public:
    ScopeLayer* root_;
};


#endif //COMPILER_SCOPE_LAYER_TREE_H
