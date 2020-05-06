//
// Created by Alexey A. Ponomarev on 03.05.2020.
//

#ifndef COMPILER_FUNCTION_STORAGE_H
#define COMPILER_FUNCTION_STORAGE_H

#include "symbol_table/symbol.h"
#include <unordered_map>
#include "components/declaration/method_declaration.h"
#include "error/errors.h"

class FunctionStorage {
public:
    static FunctionStorage& GetInstance();
    void Set(Symbol symbol, MethodDeclaration* function);
    MethodDeclaration* Get(Symbol symbol) const;
private:
    FunctionStorage() = default;
    ~FunctionStorage() = default;
    FunctionStorage(const FunctionStorage& other) = delete;
    FunctionStorage& operator= (const FunctionStorage&) = delete;
    std::unordered_map<Symbol, MethodDeclaration*> functions_;
};

#endif //COMPILER_FUNCTION_STORAGE_H
