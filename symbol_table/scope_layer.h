#ifndef COMPILER_SCOPE_LAYER_H
#define COMPILER_SCOPE_LAYER_H


#include "symbol.h"
#include "types/object.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include "types/types.h"


class ScopeLayer {
public:
    explicit ScopeLayer(ScopeLayer* parent);
    ScopeLayer();
    ~ScopeLayer();

    void DeclareVariable(Symbol symbol, std::shared_ptr<Object> type);
    void DeclareFunction(Symbol symbol, MethodDeclaration* function);

    void Put(Symbol symbol, std::shared_ptr<Object> value);
    std::shared_ptr<Object> Get(Symbol symbol);
    bool Has(Symbol symbol);

    void AddChild(ScopeLayer* child);
    void AttachParent();

    ScopeLayer* GetChild(size_t index);
    ScopeLayer* GetParent() const;

    void PrintLayer(std::ostream& stream, int num_tabs) const;
private:
    std::unordered_map<Symbol, std::shared_ptr<Object>> values_;
    std::unordered_map<Symbol, size_t> offsets_;
    std::vector<Symbol> symbols_;
    std::string name_;
    ScopeLayer* parent_;
    std::vector<ScopeLayer* > children_;
};


#endif //COMPILER_SCOPE_LAYER_H
