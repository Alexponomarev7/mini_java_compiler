#include "driver/driver.hh"
#include "parser/parser.hh"



Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
}


int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    scan_end();
    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Driver::PrintTree(const std::string& filename) {
    PrintVisitor visitor(filename);
    visitor.Visit(program);
}

int Driver::Evaluate() {
    SymbolTreeVisitor visitor;
    visitor.Visit(program);

    std::cerr << "Symbol tree built" << std::endl;
    ScopeLayerTree root = visitor.GetRoot();

    auto functions = visitor.GetFunctions();

    FunctionStorage& storage = FunctionStorage::GetInstance();
    for (auto it : functions) {
        storage.Set(it.first, it.second);
    }

    MethodDeclaration* main_function = storage.Get(Symbol("main"));

    std::shared_ptr<ClassMethodType> function_type = std::dynamic_pointer_cast<ClassMethodType>(
            root.Get(Symbol("main"))
    );

    FunctionCallVisitor function_visitor(
            root.GetFunctionScopeByName(Symbol("main")),
            function_type,
            &root
    );

    function_visitor.Visit(main_function);

    root.PrintTree("symbol_tree.txt");
    //InterpreterVisitor interpreter(root);
    //int interpreter_result = interpreter.GetResult(program);
}

void Driver::scan_end()
{
    stream.close();
}

