#pragma once

#include <map>
#include <string>
#include <fstream>
#include "scanner/scanner.h"
#include "parser/parser.hh"
#include "visitors/print_visitor.h"
#include "visitors/symbol_tree_visitor.h"
#include "visitors/interpreter_visitor.h"
#include "visitors/function_call_visitor.h"
#include "visitors/irtree_build_visitor.h"

class Driver {
public:
    Driver();
    int result;
    int parse(const std::string& f);
    int Evaluate();
    void PrintTree(const std::string& filename);
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    Program* program;
private:
    std::ifstream stream;

};
