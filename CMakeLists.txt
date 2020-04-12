cmake_minimum_required(VERSION 3.0)
project(Compiler)

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    execute_process(
            COMMAND brew --prefix bison
            RESULT_VARIABLE BREW_BISON
            OUTPUT_VARIABLE BREW_BISON_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_BISON EQUAL 0 AND EXISTS "${BREW_BISON_PREFIX}")
        message(STATUS "Found Bison keg installed by Homebrew at ${BREW_BISON_PREFIX}")
        set(BISON_EXECUTABLE "${BREW_BISON_PREFIX}/bin/bison")
    endif ()

    execute_process(
            COMMAND brew --prefix flex
            RESULT_VARIABLE BREW_FLEX
            OUTPUT_VARIABLE BREW_FLEX_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_FLEX EQUAL 0 AND EXISTS "${BREW_FLEX_PREFIX}")
        message(STATUS "Found Flex keg installed by Homebrew at ${BREW_FLEX_PREFIX}")
        set(FLEX_EXECUTABLE "${BREW_FLEX_PREFIX}/bin/flex")
        include_directories(${BREW_FLEX_PREFIX}/include)
    endif ()
endif ()

find_package(FLEX REQUIRED)
find_package(BISON 3.5 REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Compiler_SOURCE_DIR}/bin)

set(
    HEADERS
    driver/driver.hh
    ${Compiler_SOURCE_DIR}/parser/parser.hh
    )

BISON_TARGET(
    CompilerParser
    parser/parser.y
    ${Compiler_SOURCE_DIR}/parser/parser.cpp
    DEFINES_FILE ${Compiler_SOURCE_DIR}/parser/parser.hh
)

FLEX_TARGET(
    CompilerScanner
    ${Compiler_SOURCE_DIR}/scanner/scanner.l
    ${Compiler_SOURCE_DIR}/scanner/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(CompilerScanner CompilerParser)

add_executable(
    Compiler
    main.cpp
    driver/driver.cpp
    visitors/print_visitor.cpp
    visitors/interpreter_visitor.cpp
    visitors/symbol_tree_visitor.cpp
    visitors/template_visitor.cpp
        symbol_table/scope_layer.cpp
        symbol_table/scope_layer_tree.cpp
        symbol_table/symbol.cpp
        types/types.cpp
        types/boolean.cpp
        types/integer.cpp
        types/class.cpp
        types/class_method.cpp
        ${BISON_CompilerParser_OUTPUTS}
    ${FLEX_CompilerScanner_OUTPUTS}
)
target_include_directories(Compiler PRIVATE ${Compiler_SOURCE_DIR})



