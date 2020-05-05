//
// Created by Alexey A. Ponomarev on 03.05.2020.
//

#ifndef COMPILER_FUNCTION_TABLE_H
#define COMPILER_FUNCTION_TABLE_H


#include "symbol_table/symbol.h"
#include <iostream>

#include <stack>

class FunctionTable {
public:
    void Put(Symbol symbol, int value);

    void CreateVariable(Symbol symbol);


    int Get(Symbol key);

    void BeginScope();
    void EndScope();

private:
    std::unordered_map<Symbol, std::stack<int>> values_;
    std::stack<Symbol> symbols_;
};

#endif //COMPILER_FUNCTION_TABLE_H
