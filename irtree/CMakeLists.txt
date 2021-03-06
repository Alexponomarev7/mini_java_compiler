set(SOURCES
        generators/label.cpp
        generators/label.h
        generators/temporary.cpp
        generators/temporary.h
        tree_wrapper/subtree_wrapper.h
        nodes/expressions/expression.h
        nodes/base_element.h
        visitors/visitor.h
        nodes/statements/statement.h
        tree_wrapper/expression_wrapper.cpp
        tree_wrapper/expression_wrapper.h
        nodes/statements/exp_statement.cpp
        nodes/statements/exp_statement.h
        nodes/expressions/const_expression.cpp
        nodes/expressions/const_expression.h
        types/logic_operator_type.h
        types/binary_operator_type.h
        nodes/statements/jump_conditional_statement.cpp
        nodes/statements/jump_conditional_statement.h
        tree_wrapper/statement_wrapper.cpp
        tree_wrapper/statement_wrapper.h
        tree_wrapper/conditional_wrappers/conditional_wrapper.cpp
        tree_wrapper/conditional_wrappers/conditional_wrapper.h
        nodes/statements/move_statement.cpp
        nodes/statements/move_statement.h
        tree_wrapper/conditional_wrappers/negate_conditional_wrapper.cpp
        tree_wrapper/conditional_wrappers/negate_conditional_wrapper.h
        tree_wrapper/conditional_wrappers/and_conditional_wrapper.cpp
        tree_wrapper/conditional_wrappers/and_conditional_wrapper.h
        nodes/statements/seq_statement.cpp
        nodes/statements/seq_statement.h
        nodes/statements/label_statement.cpp
        nodes/statements/label_statement.h
        tree_wrapper/conditional_wrappers/or_conditional_wrapper.cpp
        tree_wrapper/conditional_wrappers/or_conditional_wrapper.h
        nodes/expressions/binop_expression.cpp
        nodes/expressions/binop_expression.h
        nodes/expressions/temp_expression.cpp
        nodes/expressions/temp_expression.h
        nodes/expressions/mem_expression.cpp
        nodes/expressions/mem_expression.h
        nodes/statements/jump_statement.cpp
        nodes/statements/jump_statement.h
        nodes/expressions/call_expression.cpp
        nodes/expressions/call_expression.h
        nodes/expression_list.cpp
        nodes/expression_list.h
        nodes/expressions/name_expression.cpp
        nodes/expressions/name_expression.h
        tree_wrapper/conditional_wrappers/relative_conditional_wrapper.cpp
        tree_wrapper/conditional_wrappers/relative_conditional_wrapper.h
        types/logic_operator_type.cpp
        types/binary_operator_type.cpp
        visitors/print_visitor.cpp
        visitors/print_visitor.h
        visitors/base_elements.h
        nodes/expressions/eseq_expression.cpp
        nodes/expressions/eseq_expression.h)

add_library(${IR_LIB} ${SOURCES})
