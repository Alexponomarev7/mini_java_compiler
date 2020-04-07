// A Bison parser, made by GNU Bison 3.5.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 22 "parser/parser.y"

    #include "driver/driver.hh"
    #include "parser/location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 54 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 145 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 47: // class
        value.YY_MOVE_OR_COPY< Class* > (YY_MOVE (that.value));
        break;

      case 50: // declaration
        value.YY_MOVE_OR_COPY< Declaration* > (YY_MOVE (that.value));
        break;

      case 64: // expr
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case 61: // formal
        value.YY_MOVE_OR_COPY< Formal* > (YY_MOVE (that.value));
        break;

      case 46: // mainClass
        value.YY_MOVE_OR_COPY< MainClass* > (YY_MOVE (that.value));
        break;

      case 54: // methodDeclaration
        value.YY_MOVE_OR_COPY< MethodDeclaration* > (YY_MOVE (that.value));
        break;

      case 66: // methodInvocation
        value.YY_MOVE_OR_COPY< MethodInvocation* > (YY_MOVE (that.value));
        break;

      case 45: // unit
        value.YY_MOVE_OR_COPY< Program* > (YY_MOVE (that.value));
        break;

      case 55: // statement
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case 52: // variableDeclaration
      case 53: // localVariableDeclaration
        value.YY_MOVE_OR_COPY< VariableDeclaration* > (YY_MOVE (that.value));
        break;

      case 41: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 40: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 63: // lvalue
      case 65: // binaryOperator
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 48: // classes
        value.YY_MOVE_OR_COPY< std::vector<Class*> > (YY_MOVE (that.value));
        break;

      case 51: // declarations
        value.YY_MOVE_OR_COPY< std::vector<Declaration*> > (YY_MOVE (that.value));
        break;

      case 62: // formals
        value.YY_MOVE_OR_COPY< std::vector<Formal*> > (YY_MOVE (that.value));
        break;

      case 56: // statements
        value.YY_MOVE_OR_COPY< std::vector<Statement*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 47: // class
        value.move< Class* > (YY_MOVE (that.value));
        break;

      case 50: // declaration
        value.move< Declaration* > (YY_MOVE (that.value));
        break;

      case 64: // expr
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case 61: // formal
        value.move< Formal* > (YY_MOVE (that.value));
        break;

      case 46: // mainClass
        value.move< MainClass* > (YY_MOVE (that.value));
        break;

      case 54: // methodDeclaration
        value.move< MethodDeclaration* > (YY_MOVE (that.value));
        break;

      case 66: // methodInvocation
        value.move< MethodInvocation* > (YY_MOVE (that.value));
        break;

      case 45: // unit
        value.move< Program* > (YY_MOVE (that.value));
        break;

      case 55: // statement
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case 52: // variableDeclaration
      case 53: // localVariableDeclaration
        value.move< VariableDeclaration* > (YY_MOVE (that.value));
        break;

      case 41: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 40: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 63: // lvalue
      case 65: // binaryOperator
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 48: // classes
        value.move< std::vector<Class*> > (YY_MOVE (that.value));
        break;

      case 51: // declarations
        value.move< std::vector<Declaration*> > (YY_MOVE (that.value));
        break;

      case 62: // formals
        value.move< std::vector<Formal*> > (YY_MOVE (that.value));
        break;

      case 56: // statements
        value.move< std::vector<Statement*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 47: // class
        value.copy< Class* > (that.value);
        break;

      case 50: // declaration
        value.copy< Declaration* > (that.value);
        break;

      case 64: // expr
        value.copy< Expression* > (that.value);
        break;

      case 61: // formal
        value.copy< Formal* > (that.value);
        break;

      case 46: // mainClass
        value.copy< MainClass* > (that.value);
        break;

      case 54: // methodDeclaration
        value.copy< MethodDeclaration* > (that.value);
        break;

      case 66: // methodInvocation
        value.copy< MethodInvocation* > (that.value);
        break;

      case 45: // unit
        value.copy< Program* > (that.value);
        break;

      case 55: // statement
        value.copy< Statement* > (that.value);
        break;

      case 52: // variableDeclaration
      case 53: // localVariableDeclaration
        value.copy< VariableDeclaration* > (that.value);
        break;

      case 41: // "number"
        value.copy< int > (that.value);
        break;

      case 40: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 63: // lvalue
      case 65: // binaryOperator
        value.copy< std::string > (that.value);
        break;

      case 48: // classes
        value.copy< std::vector<Class*> > (that.value);
        break;

      case 51: // declarations
        value.copy< std::vector<Declaration*> > (that.value);
        break;

      case 62: // formals
        value.copy< std::vector<Formal*> > (that.value);
        break;

      case 56: // statements
        value.copy< std::vector<Statement*> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 47: // class
        value.move< Class* > (that.value);
        break;

      case 50: // declaration
        value.move< Declaration* > (that.value);
        break;

      case 64: // expr
        value.move< Expression* > (that.value);
        break;

      case 61: // formal
        value.move< Formal* > (that.value);
        break;

      case 46: // mainClass
        value.move< MainClass* > (that.value);
        break;

      case 54: // methodDeclaration
        value.move< MethodDeclaration* > (that.value);
        break;

      case 66: // methodInvocation
        value.move< MethodInvocation* > (that.value);
        break;

      case 45: // unit
        value.move< Program* > (that.value);
        break;

      case 55: // statement
        value.move< Statement* > (that.value);
        break;

      case 52: // variableDeclaration
      case 53: // localVariableDeclaration
        value.move< VariableDeclaration* > (that.value);
        break;

      case 41: // "number"
        value.move< int > (that.value);
        break;

      case 40: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 63: // lvalue
      case 65: // binaryOperator
        value.move< std::string > (that.value);
        break;

      case 48: // classes
        value.move< std::vector<Class*> > (that.value);
        break;

      case 51: // declarations
        value.move< std::vector<Declaration*> > (that.value);
        break;

      case 62: // formals
        value.move< std::vector<Formal*> > (that.value);
        break;

      case 56: // statements
        value.move< std::vector<Statement*> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 47: // class
        yylhs.value.emplace< Class* > ();
        break;

      case 50: // declaration
        yylhs.value.emplace< Declaration* > ();
        break;

      case 64: // expr
        yylhs.value.emplace< Expression* > ();
        break;

      case 61: // formal
        yylhs.value.emplace< Formal* > ();
        break;

      case 46: // mainClass
        yylhs.value.emplace< MainClass* > ();
        break;

      case 54: // methodDeclaration
        yylhs.value.emplace< MethodDeclaration* > ();
        break;

      case 66: // methodInvocation
        yylhs.value.emplace< MethodInvocation* > ();
        break;

      case 45: // unit
        yylhs.value.emplace< Program* > ();
        break;

      case 55: // statement
        yylhs.value.emplace< Statement* > ();
        break;

      case 52: // variableDeclaration
      case 53: // localVariableDeclaration
        yylhs.value.emplace< VariableDeclaration* > ();
        break;

      case 41: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 40: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 63: // lvalue
      case 65: // binaryOperator
        yylhs.value.emplace< std::string > ();
        break;

      case 48: // classes
        yylhs.value.emplace< std::vector<Class*> > ();
        break;

      case 51: // declarations
        yylhs.value.emplace< std::vector<Declaration*> > ();
        break;

      case 62: // formals
        yylhs.value.emplace< std::vector<Formal*> > ();
        break;

      case 56: // statements
        yylhs.value.emplace< std::vector<Statement*> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 122 "parser/parser.y"
                        { yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < MainClass* > (), yystack_[0].value.as < std::vector<Class*> > ()); driver.program = yylhs.value.as < Program* > (); }
#line 933 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 3:
#line 126 "parser/parser.y"
    { yylhs.value.as < MainClass* > () = new MainClass(yystack_[7].value.as < std::string > (), std::move(yystack_[1].value.as < std::vector<Statement*> > ())); }
#line 939 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 4:
#line 129 "parser/parser.y"
           { yylhs.value.as < std::string > () = ""; }
#line 945 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 5:
#line 130 "parser/parser.y"
                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 951 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 6:
#line 134 "parser/parser.y"
    { yylhs.value.as < Class* > () = new Class(yystack_[4].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Declaration*> > ()); }
#line 957 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 7:
#line 137 "parser/parser.y"
           {}
#line 963 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 8:
#line 138 "parser/parser.y"
                    { yylhs.value.as < std::vector<Class*> > () = std::move(yystack_[1].value.as < std::vector<Class*> > ()); yylhs.value.as < std::vector<Class*> > ().push_back(yystack_[0].value.as < Class* > ()); }
#line 969 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 9:
#line 141 "parser/parser.y"
                        { yylhs.value.as < Declaration* > () = yystack_[0].value.as < VariableDeclaration* > (); }
#line 975 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 10:
#line 142 "parser/parser.y"
                        { yylhs.value.as < Declaration* > () = yystack_[0].value.as < MethodDeclaration* > (); }
#line 981 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 11:
#line 145 "parser/parser.y"
           {}
#line 987 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 12:
#line 146 "parser/parser.y"
                               { yylhs.value.as < std::vector<Declaration*> > () = std::move(yystack_[1].value.as < std::vector<Declaration*> > ()); yylhs.value.as < std::vector<Declaration*> > ().push_back(yystack_[0].value.as < Declaration* > ()); }
#line 993 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 13:
#line 150 "parser/parser.y"
    { yylhs.value.as < VariableDeclaration* > () = new VariableDeclaration(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ()); }
#line 999 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 14:
#line 154 "parser/parser.y"
    { yylhs.value.as < MethodDeclaration* > () = new MethodDeclaration(yystack_[7].value.as < std::string > (), yystack_[6].value.as < std::string > (), yystack_[4].value.as < std::vector<Formal*> > (), yystack_[1].value.as < std::vector<Statement*> > ()); }
#line 1005 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 15:
#line 157 "parser/parser.y"
                      { yylhs.value.as < Formal* > () = new Formal(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ()); }
#line 1011 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 16:
#line 161 "parser/parser.y"
           {}
#line 1017 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 17:
#line 162 "parser/parser.y"
                     { yylhs.value.as < std::vector<Formal*> > () = std::move(yystack_[1].value.as < std::vector<Formal*> > ()); yylhs.value.as < std::vector<Formal*> > ().push_back(yystack_[0].value.as < Formal* > ()); }
#line 1023 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 18:
#line 165 "parser/parser.y"
               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1029 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 19:
#line 166 "parser/parser.y"
                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1035 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 20:
#line 169 "parser/parser.y"
          { yylhs.value.as < std::string > () = "int"; }
#line 1041 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 21:
#line 170 "parser/parser.y"
                { yylhs.value.as < std::string > () = "boolean"; }
#line 1047 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 22:
#line 171 "parser/parser.y"
             { yylhs.value.as < std::string > () = "void"; }
#line 1053 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 23:
#line 172 "parser/parser.y"
                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1059 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 24:
#line 175 "parser/parser.y"
                       { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > (); }
#line 1065 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 25:
#line 178 "parser/parser.y"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1071 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 26:
#line 181 "parser/parser.y"
                          { yylhs.value.as < Statement* > () = new AssertStatement(yystack_[1].value.as < Expression* > ()); }
#line 1077 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 27:
#line 182 "parser/parser.y"
                               { yylhs.value.as < Statement* > () = new LocalVariableDeclarationStatement(yystack_[0].value.as < VariableDeclaration* > ()); }
#line 1083 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 28:
#line 183 "parser/parser.y"
                         { yylhs.value.as < Statement* > () = new ScopeStatements(yystack_[1].value.as < std::vector<Statement*> > ()); }
#line 1089 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 29:
#line 184 "parser/parser.y"
                                  { yylhs.value.as < Statement* > () = new IfStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ()); }
#line 1095 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 30:
#line 185 "parser/parser.y"
                                                   { yylhs.value.as < Statement* > () = new IfElseStatement(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < Statement* > (), yystack_[0].value.as < Statement* > ()); }
#line 1101 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 31:
#line 186 "parser/parser.y"
                                     { yylhs.value.as < Statement* > () = new WhileStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ()); }
#line 1107 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 32:
#line 187 "parser/parser.y"
                                            { yylhs.value.as < Statement* > () = new PrintlnStatement(yystack_[2].value.as < Expression* > ()); }
#line 1113 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 33:
#line 188 "parser/parser.y"
                          { yylhs.value.as < Statement* > () = new SetLvalueStatement(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expression* > ()); }
#line 1119 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 34:
#line 189 "parser/parser.y"
                        { yylhs.value.as < Statement* > () = new ReturnStatement(yystack_[1].value.as < Expression* > ()); }
#line 1125 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 35:
#line 190 "parser/parser.y"
                           { yylhs.value.as < Statement* > () = new MethodInvocationStatement(yystack_[1].value.as < MethodInvocation* > ()); }
#line 1131 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 36:
#line 193 "parser/parser.y"
           {}
#line 1137 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 37:
#line 194 "parser/parser.y"
                           { yylhs.value.as < std::vector<Statement*> > () = std::move(yystack_[1].value.as < std::vector<Statement*> > ()); yylhs.value.as < std::vector<Statement*> > ().push_back(yystack_[0].value.as < Statement* > ()); }
#line 1143 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 38:
#line 198 "parser/parser.y"
                        { yylhs.value.as < VariableDeclaration* > () = yystack_[0].value.as < VariableDeclaration* > (); }
#line 1149 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 39:
#line 202 "parser/parser.y"
                                  { yylhs.value.as < MethodInvocation* > () = new MethodInvocation(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < std::string > ()); }
#line 1155 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 40:
#line 206 "parser/parser.y"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1161 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 41:
#line 207 "parser/parser.y"
                                { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > (); }
#line 1167 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 42:
#line 210 "parser/parser.y"
                             { yylhs.value.as < Expression* > () = new BinaryExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > (), yystack_[1].value.as < std::string > ()); }
#line 1173 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 43:
#line 211 "parser/parser.y"
                        {}
#line 1179 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 44:
#line 212 "parser/parser.y"
      { yylhs.value.as < Expression* > () = yystack_[2].value.as < Expression* > (); }
#line 1185 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 45:
#line 213 "parser/parser.y"
                                    { yylhs.value.as < Expression* > () = new ArrayMakeExpression(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expression* > ()); }
#line 1191 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 46:
#line 214 "parser/parser.y"
                                   { yylhs.value.as < Expression* > () = new ObjectMakeExpression(yystack_[2].value.as < std::string > ()); }
#line 1197 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 47:
#line 215 "parser/parser.y"
               { yylhs.value.as < Expression* > () = new InverseExpression(yystack_[0].value.as < Expression* > ()); }
#line 1203 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 48:
#line 216 "parser/parser.y"
                   { yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); }
#line 1209 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 49:
#line 217 "parser/parser.y"
                   { yylhs.value.as < Expression* > () = new SimpleExpression(yystack_[0].value.as < std::string > ()); }
#line 1215 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 50:
#line 218 "parser/parser.y"
               { yylhs.value.as < Expression* > () = new SimpleExpression(std::to_string(yystack_[0].value.as < int > ())); }
#line 1221 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 51:
#line 219 "parser/parser.y"
             { yylhs.value.as < Expression* > () = new SimpleExpression("this"); }
#line 1227 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 52:
#line 220 "parser/parser.y"
             { yylhs.value.as < Expression* > () = new SimpleExpression("true"); }
#line 1233 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 53:
#line 221 "parser/parser.y"
              { yylhs.value.as < Expression* > () = new SimpleExpression("false"); }
#line 1239 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 54:
#line 222 "parser/parser.y"
                       { yylhs.value.as < Expression* > () = new MethodInvocationExpression(yystack_[0].value.as < MethodInvocation* > ()); }
#line 1245 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 55:
#line 228 "parser/parser.y"
           { yylhs.value.as < std::string > () = "&&"; }
#line 1251 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 56:
#line 229 "parser/parser.y"
           { yylhs.value.as < std::string > () = "||"; }
#line 1257 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 57:
#line 230 "parser/parser.y"
           { yylhs.value.as < std::string > () = "<"; }
#line 1263 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 58:
#line 231 "parser/parser.y"
           { yylhs.value.as < std::string > () = ">"; }
#line 1269 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 59:
#line 232 "parser/parser.y"
           { yylhs.value.as < std::string > () = "=="; }
#line 1275 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 60:
#line 233 "parser/parser.y"
           { yylhs.value.as < std::string > () = "+"; }
#line 1281 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 61:
#line 234 "parser/parser.y"
           { yylhs.value.as < std::string > () = "-"; }
#line 1287 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 62:
#line 235 "parser/parser.y"
           { yylhs.value.as < std::string > () = "*"; }
#line 1293 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 63:
#line 236 "parser/parser.y"
           { yylhs.value.as < std::string > () = "/"; }
#line 1299 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 64:
#line 237 "parser/parser.y"
           { yylhs.value.as < std::string > () = "%"; }
#line 1305 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;


#line 1309 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -100;

  const signed char parser::yytable_ninf_ = -41;

  const short
  parser::yypact_[] =
  {
     -26,   -35,    27,  -100,    12,  -100,    -2,     4,    19,  -100,
      39,    21,    47,    22,    44,    57,  -100,  -100,  -100,     5,
     284,  -100,     9,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,    49,  -100,    35,    66,  -100,  -100,    66,    64,    67,
      68,     9,    71,    66,  -100,  -100,  -100,    -5,  -100,  -100,
    -100,  -100,    70,   274,    65,    50,    73,    75,  -100,    11,
    -100,   314,   274,    66,    66,    66,    76,    84,    66,    62,
      66,    66,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,    66,   -29,  -100,    66,  -100,    85,  -100,  -100,  -100,
    -100,   106,   123,   148,    66,    86,   165,  -100,   190,   207,
     232,    91,  -100,   274,  -100,  -100,   374,   374,   249,  -100,
      78,  -100,  -100,  -100,   105,    18,    95,  -100,  -100,  -100,
    -100,   107,    82,  -100,   374,  -100,  -100,  -100,   344,  -100
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     7,     0,     1,     2,     0,     0,     8,
       0,     4,     0,     0,     0,     0,     5,    11,    36,     0,
       0,     6,     0,    20,    21,    22,    25,    12,     9,    10,
      19,    18,    23,     0,     0,    36,     3,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,    49,    50,    38,
      27,    37,     0,     0,    54,     0,     0,     0,    49,     0,
      54,     0,    47,     0,     0,     0,     0,    23,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,     0,    64,     0,    35,     0,    24,    13,    48,
      28,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,    44,    42,    16,    26,     0,     0,     0,    46,
       0,    41,    33,    43,     0,     0,    29,    31,    45,    32,
      39,     0,     0,    17,     0,    36,    15,    30,     0,    14
  };

  const signed char
  parser::yypgoto_[] =
  {
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,   104,  -100,
    -100,   -99,   -33,  -100,    94,    96,   -21,  -100,  -100,  -100,
     -31,  -100,   -20
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     9,     6,    14,    27,    19,    49,    50,
      29,    51,    20,    30,    31,    32,    33,   123,   115,    52,
      53,    84,    60
  };

  const short
  parser::yytable_[] =
  {
      54,    55,    61,    59,     1,     4,    62,   116,   117,   -40,
      70,   101,    69,   102,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    21,    89,   127,    81,     5,     8,     7,
      82,   121,    91,    92,    93,   -25,    10,    96,    22,    98,
      99,    54,    23,    24,    25,    26,    23,    24,    25,    26,
     100,    12,    13,   103,    83,    23,    24,    25,    26,    11,
      15,    17,    16,   108,    56,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    18,    57,    63,    81,    34,    64,
      65,    82,    97,    68,    71,    85,    54,    54,    37,    87,
      86,    94,   128,    41,   122,    88,    95,   104,   119,   109,
      44,    45,    46,   114,    54,    83,    58,    48,    54,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   120,   105,
     124,    81,   126,    28,   125,    82,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    66,   106,    67,    81,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,    83,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,   107,     0,    81,     0,     0,    83,    82,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     0,   110,     0,
      81,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,    83,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    81,   111,     0,    83,    82,
      72,    73,    74,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    81,     0,     0,     0,    82,   112,     0,     0,
       0,     0,     0,    83,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    81,   113,     0,
      83,    82,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    81,   118,     0,     0,    82,     0,
       0,     0,     0,     0,     0,    83,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    81,
       0,     0,    83,    82,     0,     0,    34,     0,     0,     0,
       0,    35,    36,     0,     0,     0,    37,    38,    39,     0,
      40,    41,    42,    43,     0,     0,     0,    83,    44,    45,
      46,    23,    24,    25,    47,    48,    34,     0,     0,     0,
       0,    35,    90,     0,     0,     0,    37,    38,    39,     0,
      40,    41,    42,    43,     0,     0,     0,     0,    44,    45,
      46,    23,    24,    25,    47,    48,    34,     0,     0,     0,
       0,    35,   129,     0,     0,     0,    37,    38,    39,     0,
      40,    41,    42,    43,     0,     0,     0,     0,    44,    45,
      46,    23,    24,    25,    47,    48,    34,     0,     0,     0,
       0,    35,     0,     0,     0,     0,    37,    38,    39,     0,
      40,    41,    42,    43,     0,     0,     0,     0,    44,    45,
      46,    23,    24,    25,    47,    48
  };

  const short
  parser::yycheck_[] =
  {
      20,    22,    35,    34,    30,    40,    37,   106,   107,    14,
      15,    40,    43,    42,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    18,    13,   124,    15,     0,    30,    17,
      19,    13,    63,    64,    65,    40,    32,    68,    33,    70,
      71,    61,    37,    38,    39,    40,    37,    38,    39,    40,
      81,    12,    31,    84,    43,    37,    38,    39,    40,    40,
      13,    17,    40,    94,    15,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    17,    40,    12,    15,    12,    12,
      12,    19,    20,    12,    14,    20,   106,   107,    22,    16,
      40,    15,   125,    27,   115,    20,    12,    12,    20,    13,
      34,    35,    36,    12,   124,    43,    40,    41,   128,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    13,    13,
      25,    15,    40,    19,    17,    19,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    41,    13,    41,    15,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    -1,    15,    -1,    -1,    43,    19,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    -1,    43,    19,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    43,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,
      43,    19,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      -1,    -1,    43,    19,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    43,    34,    35,
      36,    37,    38,    39,    40,    41,    12,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    12,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41
  };

  const signed char
  parser::yystos_[] =
  {
       0,    30,    45,    46,    40,     0,    48,    17,    30,    47,
      32,    40,    12,    31,    49,    13,    40,    17,    17,    51,
      56,    18,    33,    37,    38,    39,    40,    50,    52,    54,
      57,    58,    59,    60,    12,    17,    18,    22,    23,    24,
      26,    27,    28,    29,    34,    35,    36,    40,    41,    52,
      53,    55,    63,    64,    66,    60,    15,    40,    40,    64,
      66,    56,    64,    12,    12,    12,    58,    59,    12,    64,
      15,    14,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    15,    19,    43,    65,    20,    40,    16,    20,    13,
      18,    64,    64,    64,    15,    12,    64,    20,    64,    64,
      64,    40,    42,    64,    12,    13,    13,    13,    64,    13,
      13,    16,    20,    16,    12,    62,    55,    55,    16,    20,
      13,    13,    60,    61,    25,    17,    40,    55,    56,    18
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    49,    49,    47,    48,    48,    50,
      50,    51,    51,    52,    54,    61,    62,    62,    60,    60,
      58,    58,    58,    58,    57,    59,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    53,    66,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     9,     0,     2,     6,     0,     2,     1,
       1,     0,     2,     3,     9,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     1,     3,     5,
       7,     5,     5,     4,     3,     2,     0,     2,     1,     5,
       1,     4,     3,     4,     3,     5,     4,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"&&\"", "\"||\"", "\"<\"",
  "\">\"", "\"==\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"(\"", "\")\"",
  "\"=\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\".\"", "\";\"", "\",\"",
  "\"!\"", "\"assert\"", "\"if\"", "\"else\"", "\"while\"", "\"new\"",
  "\"System.out.println\"", "\"return\"", "\"class\"", "\"extends\"",
  "\"public static void main\"", "\"public\"", "\"this\"", "\"true\"",
  "\"false\"", "\"int\"", "\"boolean\"", "\"void\"", "\"identifier\"",
  "\"number\"", "\"length\"", "\"%\"", "$accept", "unit", "mainClass",
  "class", "classes", "extension", "declaration", "declarations",
  "variableDeclaration", "localVariableDeclaration", "methodDeclaration",
  "statement", "statements", "arrayType", "simpleType", "typeIdentifier",
  "type", "formal", "formals", "lvalue", "expr", "binaryOperator",
  "methodInvocation", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   122,   122,   125,   129,   130,   133,   137,   138,   141,
     142,   145,   146,   149,   153,   157,   161,   162,   165,   166,
     169,   170,   171,   172,   175,   178,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   193,   194,   198,   202,
     206,   207,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1838 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"

#line 239 "parser/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
