%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver/driver.hh"
    #include "parser/parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}

id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]
print System\.out\.println
main  public[ ]static[ ]void[ ]main

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = driver.location;
  // Code run each time yylex is called.
  loc.step();
%}

{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"&&"       return yy::parser::make_AND      (loc);
"||"       return yy::parser::make_OR       (loc);
"<"        return yy::parser::make_LT       (loc);
">"        return yy::parser::make_GT       (loc);
"=="       return yy::parser::make_EQUAL    (loc);
"+"        return yy::parser::make_PLUS     (loc);
"-"        return yy::parser::make_MINUS    (loc);
"*"        return yy::parser::make_STAR     (loc);
"/"        return yy::parser::make_SLASH    (loc);

"("        return yy::parser::make_LPAREN   (loc);
")"        return yy::parser::make_RPAREN   (loc);
"="        return yy::parser::make_ASSIGN   (loc);
"["        return yy::parser::make_LBRACKET (loc);
"]"        return yy::parser::make_RBRACKET (loc);
"{"        return yy::parser::make_LBRACE   (loc);
"}"        return yy::parser::make_RBRACE   (loc);
"."        return yy::parser::make_DOT      (loc);
";"        return yy::parser::make_ENDLINE  (loc);
","        return yy::parser::make_COMMA    (loc);
"!"        return yy::parser::make_NOT      (loc);

"assert"   return yy::parser::make_ASSERT   (loc);
"if"       return yy::parser::make_IF       (loc);
"else"     return yy::parser::make_ELSE     (loc);
"while"    return yy::parser::make_WHILE    (loc);
"new"      return yy::parser::make_NEW      (loc);
{print}    return yy::parser::make_PRINTLN  (loc);
"return"   return yy::parser::make_RETURN   (loc);
"class"    return yy::parser::make_CLASS    (loc);
"extends"  return yy::parser::make_EXTENDS  (loc);
{main}     return yy::parser::make_MAIN     (loc);
"public"   return yy::parser::make_PUBLIC   (loc);
"this"     return yy::parser::make_THIS     (loc);
"length"   return yy::parser::make_LENGTH   (loc);

{int}      return make_NUMBER       (yytext, loc);
"true"     return yy::parser::make_TRUE     (loc);
"false"    return yy::parser::make_FALSE    (loc);

"int"      return yy::parser::make_TYPEINT  (loc);
"boolean"  return yy::parser::make_TYPEBOOL (loc);
"void"     return yy::parser::make_TYPEVOID (loc);

{id}       return yy::parser::make_IDENTIFIER(yytext, loc);
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_END (loc);
%%

yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n, loc);
}