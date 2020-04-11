#ifndef COMPILER_TYPES_H
#define COMPILER_TYPES_H

#include "visitors/forward_decl.h"

#include "object.h"
#include "integer.h"
#include "boolean.h"
#include "class.h"

#include <vector>
#include <string>
#include <set>

#define INT_TYPE "int"
#define BOOL_TYPE "bool"

Object* GetType(const Type& type);

#endif //COMPILER_TYPES_H
