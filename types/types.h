#ifndef COMPILER_TYPES_H
#define COMPILER_TYPES_H

#include "visitors/forward_decl.h"

#include "object.h"
#include "integer.h"
#include "boolean.h"
#include "class.h"
#include "class_method.h"
#include "array.h"

#include <vector>
#include <string>
#include <set>
#include <memory>

#define INT_TYPE "int"
#define BOOL_TYPE "bool"

Object* GetType(const Type& type);

void EqualTypesOrThrow(std::shared_ptr<Object> lvalue, std::shared_ptr<Object> rvalue);

#endif //COMPILER_TYPES_H
