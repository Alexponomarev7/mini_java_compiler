#ifndef COMPILER_FORWARD_DECL_H
#define COMPILER_FORWARD_DECL_H

class Programm;

class Declaration;
class MethodDeclaration;
class VariableDeclaration;

using Identifier = std::string;
using Extension = std::string;
using Type = std::string;
using SimpleType = std::string;
using TypeIdentifier = std::string;
using ArrayType = std::string;
using Lvalue = std::string;

// classes declaration
class MainClass;
class Class;
class Program;
class Statement;
class Formal;
class Expression;
class LocalVariableDeclaration;
class MethodInvocation;

#endif //COMPILER_FORWARD_DECL_H
