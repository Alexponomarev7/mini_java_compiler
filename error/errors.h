#ifndef COMPILER_ERRORS_H
#define COMPILER_ERRORS_H

#include <stdexcept>
#include <string>
#include <sstream>
#include <location/location.h>

#define RED(text)       "\x1B[31m" text "\033[0m"
#define GREEN(text)     "\x1B[32m" text "\033[0m"
#define YELLOW(text)    "\x1B[33m" text "\033[0m"
#define BLUE(text)      "\x1B[34m" text "\033[0m"
#define MAGENTA(text)   "\x1B[35m" text "\033[0m"
#define CYAN(text)      "\x1B[36m" text "\033[0m"
#define WHITE(text)     "\x1B[37m" text "\033[0m"

struct TypeError : std::stringstream, std::exception {
};

std::runtime_error runtime_error_location(const std::string& message);

#endif //COMPILER_ERRORS_H
