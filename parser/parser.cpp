// A Bison parser, made by GNU Bison 3.6.1.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 22 "parser/parser.y"

    #include "driver/driver.hh"
    #include "parser/location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 55 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"


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
      yy_stack_print_ ();                \
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
#line 147 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"

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
  | symbol kinds.  |
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

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case 47: // class
        value.YY_MOVE_OR_COPY< Class* > (YY_MOVE (that.value));
        break;

      case 50: // declaration
        value.YY_MOVE_OR_COPY< Declaration* > (YY_MOVE (that.value));
        break;

      case 65: // expr
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

      case 67: // methodInvocation
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

      case 42: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 41: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 64: // lvalue
      case 66: // binaryOperator
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

      case 63: // params
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
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
    switch (that.kind ())
    {
      case 47: // class
        value.move< Class* > (YY_MOVE (that.value));
        break;

      case 50: // declaration
        value.move< Declaration* > (YY_MOVE (that.value));
        break;

      case 65: // expr
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

      case 67: // methodInvocation
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

      case 42: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 41: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 64: // lvalue
      case 66: // binaryOperator
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

      case 63: // params
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case 47: // class
        value.copy< Class* > (that.value);
        break;

      case 50: // declaration
        value.copy< Declaration* > (that.value);
        break;

      case 65: // expr
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

      case 67: // methodInvocation
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

      case 42: // "number"
        value.copy< int > (that.value);
        break;

      case 41: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 64: // lvalue
      case 66: // binaryOperator
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

      case 63: // params
        value.copy< std::vector<std::string> > (that.value);
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
    switch (that.kind ())
    {
      case 47: // class
        value.move< Class* > (that.value);
        break;

      case 50: // declaration
        value.move< Declaration* > (that.value);
        break;

      case 65: // expr
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

      case 67: // methodInvocation
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

      case 42: // "number"
        value.move< int > (that.value);
        break;

      case 41: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 64: // lvalue
      case 66: // binaryOperator
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

      case 63: // params
        value.move< std::vector<std::string> > (that.value);
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
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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

      case 65: // expr
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

      case 67: // methodInvocation
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

      case 42: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 41: // "identifier"
      case 49: // extension
      case 57: // arrayType
      case 58: // simpleType
      case 59: // typeIdentifier
      case 60: // type
      case 64: // lvalue
      case 66: // binaryOperator
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

      case 63: // params
        yylhs.value.emplace< std::vector<std::string> > ();
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
#line 124 "parser/parser.y"
                        { yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < MainClass* > (), yystack_[0].value.as < std::vector<Class*> > ()); driver.program = yylhs.value.as < Program* > (); yylhs.value.as < Program* > ()->SetLocation(yylhs.location); }
#line 922 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 3:
#line 128 "parser/parser.y"
    { yylhs.value.as < MainClass* > () = new MainClass(yystack_[8].value.as < std::string > (), std::move(yystack_[2].value.as < std::vector<Statement*> > ())); yylhs.value.as < MainClass* > ()->SetLocation(yylhs.location); }
#line 928 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 4:
#line 131 "parser/parser.y"
           { yylhs.value.as < std::string > () = ""; }
#line 934 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 5:
#line 132 "parser/parser.y"
                             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 940 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 6:
#line 136 "parser/parser.y"
    { yylhs.value.as < Class* > () = new Class(yystack_[4].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<Declaration*> > ()); yylhs.value.as < Class* > ()->SetLocation(yylhs.location); }
#line 946 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 7:
#line 139 "parser/parser.y"
           {}
#line 952 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 8:
#line 140 "parser/parser.y"
                    { yylhs.value.as < std::vector<Class*> > () = std::move(yystack_[1].value.as < std::vector<Class*> > ()); yylhs.value.as < std::vector<Class*> > ().push_back(yystack_[0].value.as < Class* > ()); }
#line 958 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 9:
#line 143 "parser/parser.y"
                        { yylhs.value.as < Declaration* > () = yystack_[0].value.as < VariableDeclaration* > (); yylhs.value.as < Declaration* > ()->SetLocation(yylhs.location); }
#line 964 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 10:
#line 144 "parser/parser.y"
                        { yylhs.value.as < Declaration* > () = yystack_[0].value.as < MethodDeclaration* > (); yylhs.value.as < Declaration* > ()->SetLocation(yylhs.location); }
#line 970 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 11:
#line 147 "parser/parser.y"
           {}
#line 976 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 12:
#line 148 "parser/parser.y"
                               { yylhs.value.as < std::vector<Declaration*> > () = std::move(yystack_[1].value.as < std::vector<Declaration*> > ()); yylhs.value.as < std::vector<Declaration*> > ().push_back(yystack_[0].value.as < Declaration* > ()); }
#line 982 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 13:
#line 152 "parser/parser.y"
    { yylhs.value.as < VariableDeclaration* > () = new VariableDeclaration(yystack_[2].value.as < std::string > (), yystack_[1].value.as < std::string > ()); yylhs.value.as < VariableDeclaration* > ()->SetLocation(yylhs.location); }
#line 988 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 14:
#line 156 "parser/parser.y"
    { yylhs.value.as < MethodDeclaration* > () = new MethodDeclaration(yystack_[7].value.as < std::string > (), yystack_[6].value.as < std::string > (), yystack_[4].value.as < std::vector<Formal*> > (), yystack_[1].value.as < std::vector<Statement*> > ()); yylhs.value.as < MethodDeclaration* > ()->SetLocation(yylhs.location); }
#line 994 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 15:
#line 159 "parser/parser.y"
                      { yylhs.value.as < Formal* > () = new Formal(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ()); yylhs.value.as < Formal* > ()->SetLocation(yylhs.location); }
#line 1000 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 16:
#line 162 "parser/parser.y"
           {}
#line 1006 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 17:
#line 163 "parser/parser.y"
             { yylhs.value.as < std::vector<Formal*> > () = std::vector<Formal*>(); yylhs.value.as < std::vector<Formal*> > ().push_back(yystack_[0].value.as < Formal* > ()); }
#line 1012 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 18:
#line 164 "parser/parser.y"
                         { yylhs.value.as < std::vector<Formal*> > () = std::move(yystack_[2].value.as < std::vector<Formal*> > ()); yylhs.value.as < std::vector<Formal*> > ().push_back(yystack_[0].value.as < Formal* > ()); }
#line 1018 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 19:
#line 167 "parser/parser.y"
               { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1024 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 20:
#line 168 "parser/parser.y"
                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > () + "[]"; }
#line 1030 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 21:
#line 171 "parser/parser.y"
          { yylhs.value.as < std::string > () = "int"; }
#line 1036 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 22:
#line 172 "parser/parser.y"
                { yylhs.value.as < std::string > () = "boolean"; }
#line 1042 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 23:
#line 173 "parser/parser.y"
             { yylhs.value.as < std::string > () = "void"; }
#line 1048 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 24:
#line 174 "parser/parser.y"
                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1054 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 25:
#line 177 "parser/parser.y"
                       { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > (); }
#line 1060 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 26:
#line 180 "parser/parser.y"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1066 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 27:
#line 183 "parser/parser.y"
                              { yylhs.value.as < Statement* > () = new AssertStatement(yystack_[2].value.as < Expression* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1072 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 28:
#line 184 "parser/parser.y"
                               { yylhs.value.as < Statement* > () = new LocalVariableDeclarationStatement(yystack_[0].value.as < VariableDeclaration* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location);}
#line 1078 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 29:
#line 185 "parser/parser.y"
                         { yylhs.value.as < Statement* > () = new ScopeStatements(yystack_[1].value.as < std::vector<Statement*> > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1084 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 30:
#line 186 "parser/parser.y"
                                  { yylhs.value.as < Statement* > () = new IfStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1090 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 31:
#line 187 "parser/parser.y"
                                                   { yylhs.value.as < Statement* > () = new IfElseStatement(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < Statement* > (), yystack_[0].value.as < Statement* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1096 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 32:
#line 188 "parser/parser.y"
                                     { yylhs.value.as < Statement* > () = new WhileStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1102 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 33:
#line 189 "parser/parser.y"
                                            { yylhs.value.as < Statement* > () = new PrintlnStatement(yystack_[2].value.as < Expression* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1108 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 34:
#line 190 "parser/parser.y"
                          { yylhs.value.as < Statement* > () = new SetLvalueStatement(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expression* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1114 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 35:
#line 191 "parser/parser.y"
                        { yylhs.value.as < Statement* > () = new ReturnStatement(yystack_[1].value.as < Expression* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1120 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 36:
#line 192 "parser/parser.y"
                           { yylhs.value.as < Statement* > () = new MethodInvocationStatement(yystack_[1].value.as < MethodInvocation* > ()); yylhs.value.as < Statement* > ()->SetLocation(yylhs.location); }
#line 1126 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 37:
#line 195 "parser/parser.y"
           {}
#line 1132 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 38:
#line 196 "parser/parser.y"
                           { yylhs.value.as < std::vector<Statement*> > () = std::move(yystack_[1].value.as < std::vector<Statement*> > ()); yylhs.value.as < std::vector<Statement*> > ().push_back(yystack_[0].value.as < Statement* > ()); }
#line 1138 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 39:
#line 200 "parser/parser.y"
                        { yylhs.value.as < VariableDeclaration* > () = yystack_[0].value.as < VariableDeclaration* > (); yylhs.value.as < VariableDeclaration* > ()->SetLocation(yylhs.location); }
#line 1144 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 40:
#line 203 "parser/parser.y"
           {}
#line 1150 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 41:
#line 204 "parser/parser.y"
                   { yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>(); yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ()); }
#line 1156 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 42:
#line 205 "parser/parser.y"
                              { yylhs.value.as < std::vector<std::string> > () = std::move(yystack_[2].value.as < std::vector<std::string> > ()); yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ()); }
#line 1162 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 43:
#line 209 "parser/parser.y"
                                         { yylhs.value.as < MethodInvocation* > () = new MethodInvocation(yystack_[5].value.as < Expression* > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<std::string> > ()); yylhs.value.as < MethodInvocation* > ()->SetLocation(yylhs.location); }
#line 1168 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 44:
#line 213 "parser/parser.y"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1174 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 45:
#line 214 "parser/parser.y"
                                { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > (); }
#line 1180 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 46:
#line 217 "parser/parser.y"
                             { yylhs.value.as < Expression* > () = new BinaryExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > (), yystack_[1].value.as < std::string > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1186 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 47:
#line 218 "parser/parser.y"
                        { yylhs.value.as < Expression* > () = new InverseExpression(yystack_[3].value.as < Expression* > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1192 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 48:
#line 219 "parser/parser.y"
                        { yylhs.value.as < Expression* > () = new LengthExpression(yystack_[2].value.as < Expression* > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1198 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 49:
#line 220 "parser/parser.y"
                                    { yylhs.value.as < Expression* > () = new ArrayMakeExpression(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expression* > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1204 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 50:
#line 221 "parser/parser.y"
                                   { yylhs.value.as < Expression* > () = new ObjectMakeExpression(yystack_[2].value.as < std::string > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1210 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 51:
#line 222 "parser/parser.y"
               { yylhs.value.as < Expression* > () = new InverseExpression(yystack_[0].value.as < Expression* > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1216 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 52:
#line 223 "parser/parser.y"
                   { yylhs.value.as < Expression* > () = yystack_[1].value.as < Expression* > (); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1222 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 53:
#line 224 "parser/parser.y"
                   { yylhs.value.as < Expression* > () = new SimpleExpression(yystack_[0].value.as < std::string > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1228 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 54:
#line 225 "parser/parser.y"
               { yylhs.value.as < Expression* > () = new NumberExpression(yystack_[0].value.as < int > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1234 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 55:
#line 226 "parser/parser.y"
             { yylhs.value.as < Expression* > () = new SimpleExpression("this"); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1240 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 56:
#line 227 "parser/parser.y"
             { yylhs.value.as < Expression* > () = new SimpleExpression("true"); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1246 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 57:
#line 228 "parser/parser.y"
              { yylhs.value.as < Expression* > () = new SimpleExpression("false"); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1252 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 58:
#line 229 "parser/parser.y"
                       { yylhs.value.as < Expression* > () = new MethodInvocationExpression(yystack_[0].value.as < MethodInvocation* > ()); yylhs.value.as < Expression* > ()->SetLocation(yylhs.location); }
#line 1258 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 59:
#line 235 "parser/parser.y"
           { yylhs.value.as < std::string > () = "&&"; }
#line 1264 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 60:
#line 236 "parser/parser.y"
           { yylhs.value.as < std::string > () = "||"; }
#line 1270 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 61:
#line 237 "parser/parser.y"
           { yylhs.value.as < std::string > () = "<"; }
#line 1276 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 62:
#line 238 "parser/parser.y"
           { yylhs.value.as < std::string > () = ">"; }
#line 1282 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 63:
#line 239 "parser/parser.y"
           { yylhs.value.as < std::string > () = "=="; }
#line 1288 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 64:
#line 240 "parser/parser.y"
           { yylhs.value.as < std::string > () = "+"; }
#line 1294 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 65:
#line 241 "parser/parser.y"
           { yylhs.value.as < std::string > () = "-"; }
#line 1300 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 66:
#line 242 "parser/parser.y"
           { yylhs.value.as < std::string > () = "*"; }
#line 1306 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 67:
#line 243 "parser/parser.y"
           { yylhs.value.as < std::string > () = "/"; }
#line 1312 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;

  case 68:
#line 244 "parser/parser.y"
           { yylhs.value.as < std::string > () = "%"; }
#line 1318 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"
    break;


#line 1322 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

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
    YY_STACK_PRINT ();
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

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

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
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -102;

  const signed char parser::yytable_ninf_ = -45;

  const short
  parser::yypact_[] =
  {
      -1,   -32,    33,  -102,    31,  -102,    19,    18,    10,  -102,
      40,    23,    57,    26,    58,    60,  -102,  -102,  -102,     6,
     290,  -102,   -28,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,    63,  -102,    38,    59,  -102,    62,    59,    70,    71,
      73,   -28,    77,    59,  -102,  -102,  -102,   -11,  -102,  -102,
    -102,  -102,    76,   282,    52,    50,    78,    72,  -102,    12,
    -102,   321,  -102,   282,    59,    59,    59,    83,    90,    59,
      54,    59,    59,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,    59,    -3,  -102,    59,  -102,    91,  -102,  -102,
    -102,  -102,   114,   131,   156,    59,    92,   173,  -102,   198,
     215,   240,  -102,    94,   282,   -28,    84,   383,   383,   257,
    -102,    88,  -102,  -102,  -102,    69,    74,  -102,    13,  -102,
      86,  -102,  -102,  -102,  -102,    55,  -102,    95,   -28,   383,
    -102,    85,  -102,  -102,  -102,  -102,   352,  -102
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     7,     0,     1,     2,     0,     0,     8,
       0,     4,     0,     0,     0,     0,     5,    11,    37,     0,
       0,     6,     0,    21,    22,    23,    26,    12,     9,    10,
      20,    19,    24,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    56,    57,    53,    54,    39,
      28,    38,     0,     0,    58,     0,     0,     0,    53,     0,
      58,     0,     3,    51,     0,     0,     0,     0,    24,     0,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,     0,    68,     0,    36,     0,    25,    13,
      52,    29,     0,     0,     0,     0,     0,     0,    35,     0,
       0,     0,    48,     0,    46,    16,     0,     0,     0,     0,
      50,     0,    45,    34,    47,    40,     0,    17,     0,    27,
      30,    32,    49,    33,    41,     0,    15,     0,     0,     0,
      43,     0,    37,    18,    31,    42,     0,    14
  };

  const signed char
  parser::yypgoto_[] =
  {
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   109,  -102,
    -102,  -101,   -33,  -102,    89,   102,   -21,   -15,  -102,  -102,
    -102,   -29,  -102,   -20
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     9,     6,    14,    27,    19,    49,    50,
      29,    51,    20,    30,    31,    32,    33,   117,   118,   125,
      52,    53,    85,    60
  };

  const short
  parser::yytable_[] =
  {
      54,    55,    61,   -44,    71,    59,   120,   121,    63,     4,
      23,    24,    25,    26,    70,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    21,    90,   127,    82,   134,     1,
     -26,    83,   102,     5,   128,    92,    93,    94,   103,    22,
      97,    54,    99,   100,    23,    24,    25,    26,     7,     8,
      10,    11,    12,   101,    13,    84,   104,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   109,    16,   130,    82,
      15,    34,    86,    83,    98,    17,   131,    18,    56,    57,
      62,    37,    64,    65,   116,    66,    41,    54,    54,    69,
      72,    87,    89,    44,    88,    45,    46,    84,    95,   136,
      58,    48,    96,   105,   119,   110,   115,   116,   123,    54,
     124,   129,   132,   133,     0,   126,    54,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   135,   106,    28,    82,
      67,     0,     0,    83,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    68,   107,     0,    82,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,    84,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,     0,   108,
       0,    82,     0,     0,    84,    83,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,   111,     0,    82,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,    84,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    82,   112,     0,    84,    83,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      82,     0,     0,     0,    83,   113,     0,     0,     0,     0,
       0,    84,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,    82,   114,     0,    84,    83,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    82,   122,     0,     0,    83,     0,     0,     0,
       0,     0,     0,    84,     0,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    82,     0,     0,
      84,    83,    34,     0,     0,     0,     0,    35,    36,     0,
       0,     0,    37,    38,    39,     0,    40,    41,    42,    43,
       0,     0,     0,     0,    44,    84,    45,    46,    23,    24,
      25,    47,    48,    34,     0,     0,     0,     0,    35,    91,
       0,     0,     0,    37,    38,    39,     0,    40,    41,    42,
      43,     0,     0,     0,     0,    44,     0,    45,    46,    23,
      24,    25,    47,    48,    34,     0,     0,     0,     0,    35,
     137,     0,     0,     0,    37,    38,    39,     0,    40,    41,
      42,    43,     0,     0,     0,     0,    44,     0,    45,    46,
      23,    24,    25,    47,    48,    34,     0,     0,     0,     0,
      35,     0,     0,     0,     0,    37,    38,    39,     0,    40,
      41,    42,    43,     0,     0,     0,     0,    44,     0,    45,
      46,    23,    24,    25,    47,    48
  };

  const short
  parser::yycheck_[] =
  {
      20,    22,    35,    14,    15,    34,   107,   108,    37,    41,
      38,    39,    40,    41,    43,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    18,    13,    13,    15,   129,    30,
      41,    19,    35,     0,    21,    64,    65,    66,    41,    33,
      69,    61,    71,    72,    38,    39,    40,    41,    17,    30,
      32,    41,    12,    82,    31,    43,    85,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    95,    41,    13,    15,
      13,    12,    20,    19,    20,    17,    21,    17,    15,    41,
      18,    22,    12,    12,   105,    12,    27,   107,   108,    12,
      14,    41,    20,    34,    16,    36,    37,    43,    15,   132,
      41,    42,    12,    12,    20,    13,    12,   128,    20,   129,
      41,    25,    17,   128,    -1,    41,   136,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    41,    13,    19,    15,
      41,    -1,    -1,    19,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    41,    13,    -1,    15,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    -1,    -1,    43,    19,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    -1,    43,    19,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    43,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    -1,    43,    19,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    -1,    -1,
      43,    19,    12,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    34,    43,    36,    37,    38,    39,
      40,    41,    42,    12,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    12,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    12,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,    30,    45,    46,    41,     0,    48,    17,    30,    47,
      32,    41,    12,    31,    49,    13,    41,    17,    17,    51,
      56,    18,    33,    38,    39,    40,    41,    50,    52,    54,
      57,    58,    59,    60,    12,    17,    18,    22,    23,    24,
      26,    27,    28,    29,    34,    36,    37,    41,    42,    52,
      53,    55,    64,    65,    67,    60,    15,    41,    41,    65,
      67,    56,    18,    65,    12,    12,    12,    58,    59,    12,
      65,    15,    14,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    15,    19,    43,    66,    20,    41,    16,    20,
      13,    18,    65,    65,    65,    15,    12,    65,    20,    65,
      65,    65,    35,    41,    65,    12,    13,    13,    13,    65,
      13,    13,    16,    20,    16,    12,    60,    61,    62,    20,
      55,    55,    16,    20,    41,    63,    41,    13,    21,    25,
      13,    21,    17,    61,    55,    41,    56,    18
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    49,    49,    47,    48,    48,    50,
      50,    51,    51,    52,    54,    61,    62,    62,    62,    60,
      60,    58,    58,    58,    58,    57,    59,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    53,
      63,    63,    63,    67,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    10,     0,     2,     6,     0,     2,     1,
       1,     0,     2,     3,     9,     2,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     5,     1,     3,
       5,     7,     5,     5,     4,     3,     2,     0,     2,     1,
       0,     1,     3,     6,     1,     4,     3,     4,     3,     5,
       4,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"&&\"", "\"||\"",
  "\"<\"", "\">\"", "\"==\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"(\"",
  "\")\"", "\"=\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\".\"", "\";\"",
  "\",\"", "\"!\"", "\"assert\"", "\"if\"", "\"else\"", "\"while\"",
  "\"new\"", "\"System.out.println\"", "\"return\"", "\"class\"",
  "\"extends\"", "\"public static void main\"", "\"public\"", "\"this\"",
  "\"length\"", "\"true\"", "\"false\"", "\"int\"", "\"boolean\"",
  "\"void\"", "\"identifier\"", "\"number\"", "\"%\"", "$accept", "unit",
  "mainClass", "class", "classes", "extension", "declaration",
  "declarations", "variableDeclaration", "localVariableDeclaration",
  "methodDeclaration", "statement", "statements", "arrayType",
  "simpleType", "typeIdentifier", "type", "formal", "formals", "params",
  "lvalue", "expr", "binaryOperator", "methodInvocation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   124,   124,   127,   131,   132,   135,   139,   140,   143,
     144,   147,   148,   151,   155,   159,   162,   163,   164,   167,
     168,   171,   172,   173,   174,   177,   180,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   195,   196,   200,
     203,   204,   205,   209,   213,   214,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
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
#line 1934 "/Users/lexolordan/compilers/compiler/parser/parser.cpp"

#line 246 "parser/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
