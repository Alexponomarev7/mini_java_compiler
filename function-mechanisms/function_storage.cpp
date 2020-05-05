//
// Created by Alexey A. Ponomarev on 03.05.2020.
//

#include "function_storage.h"

FunctionStorage &FunctionStorage::GetInstance() {
    static FunctionStorage storage;
    return storage;
}

void FunctionStorage::Set(Symbol symbol, MethodDeclaration *function) {
    functions_[symbol] = function;
}


MethodDeclaration *FunctionStorage::Get(Symbol symbol) const {
    if (functions_.find(symbol) != functions_.end()) {
        return functions_.at(symbol);
    } else {
        throw std::runtime_error("Function not found");
    }
}
