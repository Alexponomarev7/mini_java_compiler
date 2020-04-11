#ifndef COMPILER_TABLE_H
#define COMPILER_TABLE_H

#include <unordered_map>
#include <stack>
#include <visitors/forward_decl.h>
#include "symbol.h"
#include "types/object.h"

class Table {
public:
    Table();
    void Put(Symbol symbol, std::shared_ptr<Object> value);

    void CreateVariable(Type type, Symbol symbol);

    Symbol GetSymbol(const std::string& name);

    std::shared_ptr<Object> Get(Symbol key);

    void BeginScope();
    void EndScope();
private:
    std::unordered_map<Symbol, std::stack<std::shared_ptr<Object>>> values_;
    std::unordered_map<std::string, Symbol> symbols_map_;

    std::stack<Symbol> symbols_;

};


#endif //COMPILER_TABLE_H
