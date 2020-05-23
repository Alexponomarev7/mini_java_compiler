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

set(
    SOURCES
    irtree/generators/label.cpp
    irtree/generators/temporary.cpp
    irtree/tree_wrapper/expression_wrapper.cpp
    irtree/nodes/statements/exp_statement.cpp
    irtree/nodes/expressions/const_expression.cpp
    irtree/types/logic_operator_type.cpp
    irtree/types/binary_operator_type.cpp
    irtree/nodes/statements/jump_conditional_statement.cpp
    irtree/tree_wrapper/statement_wrapper.cpp
    irtree/tree_wrapper/conditional_wrappers/conditional_wrapper.cpp
    irtree/nodes/statements/move_statement.cpp
    irtree/tree_wrapper/conditional_wrappers/negate_conditional_wrapper.cpp
    irtree/tree_wrapper/conditional_wrappers/and_conditional_wrapper.cpp
    irtree/nodes/statements/seq_statement.cpp
    irtree/nodes/statements/label_statement.cpp
    irtree/tree_wrapper/conditional_wrappers/or_conditional_wrapper.cpp
    irtree/nodes/expressions/binop_expression.cpp
    irtree/nodes/expressions/temp_expression.cpp
    irtree/nodes/expressions/mem_expression.cpp
    irtree/nodes/statements/jump_statement.cpp
    irtree/nodes/expressions/call_expression.cpp
    irtree/nodes/expression_list.cpp
    irtree/nodes/expressions/name_expression.cpp
    irtree/tree_wrapper/conditional_wrappers/relative_conditional_wrapper.cpp
    irtree/types/logic_operator_type.cpp
    irtree/types/binary_operator_type.cpp
    irtree/visitors/print_visitor.cpp
    irtree/visitors/double_call_eliminate_visitor.cpp
    irtree/visitors/irtemplate_visitor.cpp
    irtree/visitors/eseq_up_visitor.cpp
    irtree/visitors/block_visitor.cpp
    irtree/nodes/expressions/eseq_expression.cpp
    irtree/helpers/block.cpp
    irtree/helpers/trace.cpp
    driver/driver.cpp
    visitors/print_visitor.cpp
    visitors/interpreter_visitor.cpp
    visitors/symbol_tree_visitor.cpp
    visitors/template_visitor.cpp
    visitors/function_call_visitor.cpp
    visitors/irtree_build_visitor.cpp
    symbol_table/scope_layer.cpp
    symbol_table/scope_layer_tree.cpp
    symbol_table/symbol.cpp
    symbol_table/table.cpp
    location/location.cpp
    error/errors.cpp
    types/types.cpp
    types/boolean.cpp
    types/integer.cpp
    types/class.cpp
    types/class_method.cpp
    types/array.cpp
    function-mechanisms/function_storage.cpp
    function-mechanisms/function_table.cpp
    function-mechanisms/frame_emulator.cpp
    function-mechanisms/frame_translator.cpp
    function-mechanisms/address/address_in_frame.cpp
    function-mechanisms/address/address_in_register.cpp
    ${BISON_CompilerParser_OUTPUTS}
    ${FLEX_CompilerScanner_OUTPUTS}
)

add_executable(
    Compiler
    main.cpp
    ${SOURCES}
)


target_include_directories(Compiler PRIVATE ${Compiler_SOURCE_DIR})


