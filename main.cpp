#include <iostream>
#include <driver/driver.hh>

int main(int argc, char** argv) {
    int result = 0;
    Driver driver;

    bool evaluate = false;
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            driver.trace_parsing = true;
        } else if (argv[i] == std::string("-s")) {
            driver.trace_scanning = true;
        } else if (argv[i] == std::string("-e")) {
            evaluate = true;
        } else {
            driver.parse(argv[i]);
            driver.PrintTree(argv[i + 1]);
            ++i;

            if (evaluate) {
                driver.Evaluate();
            }
        }

    }

    return result;
}