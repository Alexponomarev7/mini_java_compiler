//
// Created by Alexey A. Ponomarev on 03.05.2020.
//

#include "function_table.h"

void FunctionTable::Put(Symbol symbol, int value) {
    std::cerr << "Put " << symbol.GetName() << " value " << value << std::endl;
    if (values_.find(symbol) == values_.end()) {
        throw runtime_error_location("Variable " + symbol.GetName() + " not declared");
    }
    values_[symbol].pop();
    values_[symbol].push(value);
    symbols_.push(symbol);
}

int FunctionTable::Get(Symbol symbol) {
    if (values_.find(symbol) == values_.end()) {
        throw runtime_error_location("Variable " + symbol.GetName() + " not declared");
    }
    return values_[symbol].top();
}

void FunctionTable::CreateVariable(Symbol symbol) {
    std::cerr << "Creating variable " << symbol.GetName() << std::endl;
    if (values_.find(symbol) == values_.end()) {
        values_[symbol] = std::stack<int>();
    }
    values_[symbol].push(0);
}

void FunctionTable::BeginScope() {
    symbols_.push(Symbol("{"));
}

void FunctionTable::EndScope() {
    while (symbols_.top() != Symbol("{")) {
        Symbol symbol = symbols_.top();

        std::cerr << "Popping " << symbol.GetName() << std::endl;

        values_[symbol].pop();
        if (values_[symbol].empty()) {
            values_.erase(symbol);
        }
        symbols_.pop();
    }
    symbols_.pop();
}
