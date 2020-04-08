#ifndef COMPILER_FORWARD_DECL_H
#define COMPILER_FORWARD_DECL_H

#include <string>

using Identifier = std::string;
using Extension = std::string;
using Type = std::string;
using SimpleType = std::string;
using TypeIdentifier = std::string;
using ArrayType = std::string;
using Lvalue = std::string;

// classes declaration
class Program;

class Declaration;
class MethodDeclaration;
class VariableDeclaration;

class MainClass;
class Class;
class Formal;
class MethodInvocation;

class Expression;
class ArrayMakeExpression;
class BinaryExpression;
class InverseExpression;
class MethodInvocationExpression;
class ObjectMakeExpression;
class SimpleExpression;

class Statement;
class AssertStatement;
class IfElseStatement;
class IfStatement;
class LocalVariableDeclarationStatement;
class MethodInvocationStatement;
class PrintlnStatement;
class ReturnStatement;
class ScopeStatements;
class SetLvalueStatement;
class WhileStatement;

#endif //COMPILER_FORWARD_DECL_H
