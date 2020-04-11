#ifndef COMPILER_COMPONENTS_H
#define COMPILER_COMPONENTS_H

#include "base.h"
#include "class.h"
#include "main_class.h"
#include "program.h"
#include "formal.h"
#include "method_invocation.h"

#include "declaration/declaration.h"
#include "declaration/variable_declaration.h"
#include "declaration/method_declaration.h"

#include "expression/expression.h"
#include "expression/array_make_expression.h"
#include "expression/binary_expression.h"
#include "expression/object_make_expression.h"
#include "expression/inverse_expression.h"
#include "expression/simple_expression.h"
#include "expression/method_invocation_expression.h"
#include "expression/length_expression.h"
#include "expression/number_expression.h"

#include "statement/statement.h"
#include "statement/assert_statement.h"
#include "statement/local_variable_declaration_statement.h"
#include "statement/scope_statements.h"
#include "statement/if_statement.h"
#include "statement/if_else_statement.h"
#include "statement/while_statement.h"
#include "statement/println_statement.h"
#include "statement/set_lvalue_statement.h"
#include "statement/return_statement.h"
#include "statement/method_invocation_statement.h"

using Identifier = std::string;
using Extension = std::string;
using Type = std::string;
using SimpleType = std::string;
using TypeIdentifier = std::string;
using ArrayType = std::string;

#endif //COMPILER_COMPONENTS_H
