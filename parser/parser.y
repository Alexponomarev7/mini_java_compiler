%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include "components/components.h"

    class Scanner;
    class Driver;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver/driver.hh"
    #include "parser/location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0       "end of file"

    // binary operators
    AND         "&&"
    OR          "||"
    LT          "<"
    GT          ">"
    EQUAL       "=="
    PLUS        "+"
    MINUS       "-"
    STAR        "*"
    SLASH       "/"

    // help
    LPAREN      "("
    RPAREN      ")"
    ASSIGN      "="
    LBRACKET    "["
    RBRACKET    "]"
    LBRACE      "{"
    RBRACE      "}"
    DOT         "."
    ENDLINE     ";"
    COMMA       ","
    NOT         "!"

    // system words
    ASSERT      "assert"
    IF          "if"
    ELSE        "else"
    WHILE       "while"
    NEW         "new"
    PRINTLN     "System.out.println"
    RETURN      "return"
    CLASS       "class"
    EXTENDS     "extends"
    MAIN        "public static void main"
    PUBLIC      "public"
    THIS        "this"
    LENGTH      "length"

    // literals
    TRUE        "true"
    FALSE       "false"

    // types
    TYPEINT     "int"
    TYPEBOOL    "boolean"
    TYPEVOID    "void"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"

%nterm <Program*> unit
%nterm <MainClass*> mainClass
%nterm <Class*> class
%nterm <std::vector<Class*>> classes
%nterm <std::string> extension
%nterm <Declaration*> declaration
%nterm <std::vector<Declaration*>> declarations
%nterm <VariableDeclaration*> variableDeclaration
%nterm <VariableDeclaration*> localVariableDeclaration
%nterm <MethodDeclaration*> methodDeclaration
%nterm <Statement*> statement
%nterm <std::vector<Statement*>> statements
%nterm <std::string> arrayType
%nterm <std::string> simpleType
%nterm <std::string> typeIdentifier
%nterm <std::string> type
%nterm <Formal*> formal
%nterm <std::vector<Formal*>> formals
%nterm <std::vector<std::string>> params
%nterm <std::string> lvalue
%nterm <Expression*> expr
%nterm <std::string> binaryOperator
%nterm <MethodInvocation*> methodInvocation

// %printer { yyo << $$; } <*>;

%%
%start unit;

unit: mainClass classes { $$ = new Program($1, $2); driver.program = $$; };

mainClass:
    "class" "identifier" "{" "public static void main" "(" ")" "{" statements "}" "}"
    { $$ = new MainClass($2, std::move($8)); }

extension:
    %empty { $$ = ""; }
    | "extends" "identifier" { $$ = $2; }

class:
    "class" "identifier" extension "{" declarations "}"
    { $$ = new Class($2, $3, $5); }

classes:
    %empty {}
    | classes class { $$ = std::move($1); $$.push_back($2); }

declaration:
    variableDeclaration { $$ = $1; }
    | methodDeclaration { $$ = $1; }

declarations:
    %empty {}
    | declarations declaration { $$ = std::move($1); $$.push_back($2); }

variableDeclaration:
    type "identifier" ";"
    { $$ = new VariableDeclaration($1, $2); }

methodDeclaration:
    "public" type "identifier" "(" formals ")" "{" statements "}"
    { $$ = new MethodDeclaration($2, $3, $5, $8); }

formal:
    type "identifier" { $$ = new Formal($1, $2); }

formals:
    %empty {}
    | formal { $$ = std::vector<Formal*>(); $$.push_back($1); }
    | formals "," formal { $$ = std::move($1); $$.push_back($3); }

type:
    simpleType { $$ = $1; }
    | arrayType { $$ = $1 + "[]"; }

simpleType:
    "int" { $$ = "int"; }
    | "boolean" { $$ = "boolean"; }
    | "void" { $$ = "void"; }
    | typeIdentifier { $$ = $1; }

arrayType:
    simpleType "[" "]" { $$ = $1; }

typeIdentifier:
    "identifier" { $$ = $1; }

statement:
    "assert" "(" expr ")" ";" { $$ = new AssertStatement($3); }
    | localVariableDeclaration { $$ = new LocalVariableDeclarationStatement($1); }
    | "{" statements "}" { $$ = new ScopeStatements($2); }
    | "if" "(" expr ")" statement { $$ = new IfStatement($3, $5); }
    | "if" "(" expr ")" statement "else" statement { $$ = new IfElseStatement($3, $5, $7); }
    | "while" "(" expr ")" statement { $$ = new WhileStatement($3, $5); }
    | "System.out.println" "(" expr ")" ";" { $$ = new PrintlnStatement($3); }
    | lvalue "=" expr ";" { $$ = new SetLvalueStatement($1, $3); }
    | "return" expr ";" { $$ = new ReturnStatement($2); }
    | methodInvocation ";" { $$ = new MethodInvocationStatement($1); }

statements:
    %empty {}
    | statements statement { $$ = std::move($1); $$.push_back($2); }


localVariableDeclaration:
    variableDeclaration { $$ = $1; }

params:
    %empty {}
    | "identifier" { $$ = std::vector<std::string>(); $$.push_back($1); }
    | params "," "identifier" { $$ = std::move($1); $$.push_back($3); }

// Need Fix
methodInvocation:
    expr "." "identifier" "(" params ")" { $$ = new MethodInvocation($1, $3, $5); }

// need fix
lvalue:
    "identifier" { $$ = $1; }
    | "identifier" "[" expr "]" { $$ = $1; } // need fix

expr:
    expr binaryOperator expr { $$ = new BinaryExpression($1, $3, $2); }
    | expr "[" expr "]" { $$ = new InverseExpression($1); } // need fix
    | expr "." "length" { $$ = new LengthExpression($1); }
    | "new" simpleType "[" expr "]" { $$ = new ArrayMakeExpression($2, $4); }
    | "new" typeIdentifier "(" ")" { $$ = new ObjectMakeExpression($2); }
    | "!" expr { $$ = new InverseExpression($2); }
    | "(" expr ")" { $$ = $2; }
    | "identifier" { $$ = new SimpleExpression($1); }
    | "number" { $$ = new NumberExpression($1); }
    | "this" { $$ = new SimpleExpression("this"); }
    | "true" { $$ = new SimpleExpression("true"); }
    | "false" { $$ = new SimpleExpression("false"); }
    | methodInvocation { $$ = new MethodInvocationExpression($1); }

%left "+" "-";
%left "*" "/" "%";

binaryOperator:
    "&&"   { $$ = "&&"; }
    | "||" { $$ = "||"; }
    | "<"  { $$ = "<"; }
    | ">"  { $$ = ">"; }
    | "==" { $$ = "=="; }
    | "+"  { $$ = "+"; }
    | "-"  { $$ = "-"; }
    | "*"  { $$ = "*"; }
    | "/"  { $$ = "/"; }
    | "%"  { $$ = "%"; }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
