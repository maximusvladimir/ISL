/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "grammar.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern void yyerror(Driver d, char const* s);

#line 78 "grammar.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.hpp".  */
#ifndef YY_YY_GRAMMAR_TAB_HPP_INCLUDED
# define YY_YY_GRAMMAR_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRIM_TYPE_STRING = 258,
    PRIM_TYPE_LIST = 259,
    PRIM_TYPE_SET = 260,
    PRIM_TYPE_I8 = 261,
    PRIM_TYPE_I16 = 262,
    PRIM_TYPE_I32 = 263,
    PRIM_TYPE_I64 = 264,
    PRIM_TYPE_UI8 = 265,
    PRIM_TYPE_UI16 = 266,
    PRIM_TYPE_UI32 = 267,
    PRIM_TYPE_UI64 = 268,
    PRIM_TYPE_F32 = 269,
    PRIM_TYPE_F64 = 270,
    PRIM_TYPE_BOOL = 271,
    PRIM_TYPE_VAR = 272,
    OPERATOR_ASSIGNMENT = 273,
    OPERATOR_DEEP_ASSIGNMENT = 274,
    OPERATOR_SET_TO = 275,
    OPERATOR_SET_SKIP = 276,
    OPERATOR_SET_FROM = 277,
    OPERATOR_BOOL_LESS_OR_EQ = 278,
    OPERATOR_BOOL_GREAT_OR_EQ = 279,
    OPERATOR_BOOL_NEQ = 280,
    OPERATOR_LOGICAL_OR = 281,
    OPERATOR_LOGICAL_AND = 282,
    OPERATOR_MULT_ASSIGN = 283,
    OPERATOR_DIV_ASSIGN = 284,
    OPERATOR_ADD_ASSIGN = 285,
    OPERATOR_SUB_ASSIGN = 286,
    OPERATOR_MOD_ASSIGN = 287,
    OPERATOR_INC = 288,
    OPERATOR_DEC = 289,
    SYM_STR_CHAR = 290,
    KEY_FOR_LOOP = 291,
    KEY_IF = 292,
    KEY_ELSE = 293,
    KEY_RETURN = 294,
    KEY_BREAK = 295,
    KEY_WHILE = 296,
    KEY_FUNC = 297,
    IDENTIFIER = 298,
    INT_NUMBER = 299,
    I64_NUMBER = 300,
    F32_NUMBER = 301,
    F64_NUMBER = 302,
    BOOL_NUMBER = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "grammar.y" /* yacc.c:355  */

	int i32val;
	long i64val;
	float f32val;
	double f64val;
	int bval;
	char* str;
	Plane* plane;

#line 177 "grammar.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (Driver driver);

#endif /* !YY_YY_GRAMMAR_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 194 "grammar.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   450

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,    52,
      49,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,     2,     2,     2,    65,     2,     2,
      50,    51,    63,    61,    53,    62,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,    58,    60,     2,    70,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,    67,    57,    68,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    84,    85,    86,    90,    91,    92,    93,
      94,    95,    96,    97,   101,   102,   103,   104,   105,   106,
     110,   111,   112,   113,   114,   118,   119,   120,   124,   125,
     129,   130,   134,   135,   139,   140,   144,   145,   146,   147,
     151,   155,   156,   160,   161,   165,   166,   170,   171,   175,
     176,   177,   178,   182,   183,   187,   188,   192,   193,   197,
     198,   202,   203,   207,   208,   212,   213,   214,   218,   219,
     220,   221,   222,   226,   227,   228,   232,   233,   234,   235,
     239,   240,   244,   245,   246,   247,   248,   252,   253,   254,
     255,   259,   260,   261,   262,   263,   264,   268,   269,   270,
     271,   275,   276,   277,   278,   279,   280,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRIM_TYPE_STRING", "PRIM_TYPE_LIST",
  "PRIM_TYPE_SET", "PRIM_TYPE_I8", "PRIM_TYPE_I16", "PRIM_TYPE_I32",
  "PRIM_TYPE_I64", "PRIM_TYPE_UI8", "PRIM_TYPE_UI16", "PRIM_TYPE_UI32",
  "PRIM_TYPE_UI64", "PRIM_TYPE_F32", "PRIM_TYPE_F64", "PRIM_TYPE_BOOL",
  "PRIM_TYPE_VAR", "OPERATOR_ASSIGNMENT", "OPERATOR_DEEP_ASSIGNMENT",
  "OPERATOR_SET_TO", "OPERATOR_SET_SKIP", "OPERATOR_SET_FROM",
  "OPERATOR_BOOL_LESS_OR_EQ", "OPERATOR_BOOL_GREAT_OR_EQ",
  "OPERATOR_BOOL_NEQ", "OPERATOR_LOGICAL_OR", "OPERATOR_LOGICAL_AND",
  "OPERATOR_MULT_ASSIGN", "OPERATOR_DIV_ASSIGN", "OPERATOR_ADD_ASSIGN",
  "OPERATOR_SUB_ASSIGN", "OPERATOR_MOD_ASSIGN", "OPERATOR_INC",
  "OPERATOR_DEC", "SYM_STR_CHAR", "KEY_FOR_LOOP", "KEY_IF", "KEY_ELSE",
  "KEY_RETURN", "KEY_BREAK", "KEY_WHILE", "KEY_FUNC", "IDENTIFIER",
  "INT_NUMBER", "I64_NUMBER", "F32_NUMBER", "F64_NUMBER", "BOOL_NUMBER",
  "'\\n'", "'('", "')'", "'\\t'", "','", "'['", "']'", "'{'", "'}'", "'='",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'|'", "'~'",
  "'!'", "'@'", "$accept", "program", "rootblock_list", "statement",
  "assign_update_statement", "block", "else_chain", "func_head",
  "sub_block", "maybe_sub_block", "func_vars", "func_vars_tail",
  "from_to_base", "from_to", "func_call", "func_arg_list",
  "func_arg_list_tail", "gen_exp", "list_def", "list_def_tail", "set_def",
  "set_def_tail", "logicor_or_math_exp", "logicand_or_math_exp",
  "logiceq_or_math_exp", "bool_or_math_exp", "add_math_exp",
  "mult_math_exp", "pow_exp", "unary_exp", "unary_operator", "postfix_exp",
  "index", "constant", "var_type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    10,
      40,    41,     9,    44,    91,    93,   123,   125,    61,    60,
      62,    43,    45,    42,    47,    37,    94,   124,   126,    33,
      64
};
# endif

#define YYPACT_NINF -190

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-190)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     197,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,   -34,   358,   238,    20,
     400,  -190,    74,  -190,   197,    41,  -190,  -190,    46,    25,
      86,    53,    53,  -190,   -37,  -190,  -190,  -190,  -190,  -190,
     358,   268,   298,  -190,  -190,    53,  -190,  -190,  -190,    62,
    -190,  -190,    56,    82,   -23,     6,    16,   -42,    51,  -190,
      53,    60,  -190,  -190,    63,    68,   358,   358,   358,   358,
     358,   358,   328,  -190,  -190,  -190,  -190,    13,  -190,   358,
     102,    76,  -190,  -190,    89,  -190,    77,  -190,    28,  -190,
     -43,    64,    33,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,  -190,  -190,  -190,
    -190,   147,  -190,  -190,  -190,  -190,  -190,  -190,  -190,    78,
      87,   358,   358,  -190,   107,   358,    33,  -190,   358,  -190,
    -190,   358,  -190,  -190,   358,  -190,  -190,  -190,   212,  -190,
      92,  -190,    82,   -23,     6,     6,    16,    16,    16,    16,
     -42,   -42,    51,    51,    51,  -190,    94,    90,   101,  -190,
     358,  -190,    97,    98,   358,  -190,  -190,    38,    28,   -43,
      96,   -29,  -190,    33,   116,   114,    87,  -190,  -190,  -190,
    -190,   358,  -190,  -190,  -190,   358,    33,  -190,    33,   253,
    -190,  -190,   117,   120,  -190,  -190,   114,   128,  -190,    33,
    -190,   114,    92,  -190,  -190
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,     0,     0,
       0,     5,     0,     2,     4,     0,    13,    24,     0,     0,
       0,     0,     0,   106,    92,   101,   102,   103,   104,   105,
       0,     0,     0,    89,    88,     0,    87,    90,    91,     0,
      51,    52,    50,    61,    63,    65,    68,    73,    76,    80,
       0,    82,    94,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     3,    10,     9,     0,    23,     0,
      42,     0,    84,    85,     0,    93,     0,    54,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    95,    96,
      11,     0,    14,    15,    16,    17,    18,    19,    44,     0,
      46,     0,     0,     6,     0,     0,     0,    98,     0,    97,
      49,     0,    56,    53,     0,    60,    57,    83,     0,    31,
      21,    30,    62,    64,    67,    66,    71,    72,    69,    70,
      74,    75,    77,    78,    79,    81,     0,     0,     0,    43,
       0,    45,     0,     0,     0,    41,    20,     0,     0,     0,
      33,     0,    22,     0,     0,    34,    48,     7,     8,    40,
      99,     0,    55,    59,    32,     0,     0,    28,     0,     0,
      35,    47,     0,     0,    25,    29,    37,     0,   100,     0,
      36,    39,    26,    38,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,   148,     4,  -190,  -190,   -28,   146,  -115,     8,
    -190,  -189,  -190,  -190,     0,  -190,     1,   -15,  -190,    11,
    -190,    12,  -190,    83,    88,     7,   -82,     3,   -44,   -26,
    -190,  -190,  -190,    99,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,   139,    25,    26,   172,    27,   140,   141,
     157,   190,    80,    81,    48,   119,   161,    49,    50,   133,
      51,   136,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    85,    62,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,   158,    95,    64,    24,    82,    83,   200,   185,    30,
     134,   166,   203,    72,   135,   146,   147,   148,   149,    91,
     186,   103,   104,   105,    28,    86,    88,    90,    24,    97,
      98,   121,   122,    84,   107,    96,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   112,   113,   114,   115,   116,   117,   120,   187,   152,
     153,   154,   123,    65,   124,    99,   100,    19,    77,    16,
      17,   194,    18,   195,    73,    19,    20,   101,   102,   197,
     155,   131,    93,   132,   202,   138,    31,    32,    33,   180,
      75,   181,    28,   108,   109,    76,    34,    35,    36,    37,
      38,    39,   144,   145,   150,   151,   162,   163,    79,    94,
     165,    92,   110,   167,    43,    44,   168,   106,   111,   169,
      45,    46,    47,   125,    33,   126,    28,   164,   130,   159,
     171,   137,   127,    35,    36,    37,    38,    39,    28,   128,
     160,   174,   170,   173,   175,   176,   177,   178,   138,   179,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   188,   192,   189,   198,   199,
     193,   201,    74,    28,   204,    78,   142,   191,   184,   182,
       0,   183,   143,   129,     0,     0,    28,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,    28,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,    16,    17,     0,    18,     0,     0,    19,
      20,     0,     0,     0,     0,     0,    21,     0,    16,    17,
       0,    18,     0,     0,    19,    20,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    31,    32,    33,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,    37,    38,    39,    63,    40,     0,
       0,     0,    41,     0,    42,     0,   196,     0,     0,    43,
      44,    31,    32,    33,     0,    45,    46,    47,     0,     0,
       0,    34,    35,    36,    37,    38,    39,     0,    40,     0,
       0,     0,    41,    87,    42,     0,     0,     0,     0,    43,
      44,    31,    32,    33,     0,    45,    46,    47,     0,     0,
       0,    34,    35,    36,    37,    38,    39,     0,    40,     0,
       0,     0,    41,     0,    42,    89,     0,     0,     0,    43,
      44,    31,    32,    33,     0,    45,    46,    47,     0,     0,
       0,    34,    35,    36,    37,    38,    39,     0,    40,   118,
       0,     0,    41,     0,    42,     0,     0,     0,     0,    43,
      44,    31,    32,    33,     0,    45,    46,    47,     0,     0,
       0,    34,    35,    36,    37,    38,    39,     0,    40,     0,
       0,     0,    41,     0,    42,     0,     0,     0,    66,    43,
      44,     0,     0,     0,     0,    45,    46,    47,    67,    68,
      69,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72
};

static const yytype_int16 yycheck[] =
{
       0,   111,    25,    18,     0,    31,    32,   196,    37,    43,
      53,   126,   201,    50,    57,    97,    98,    99,   100,    45,
      49,    63,    64,    65,    24,    40,    41,    42,    24,    23,
      24,    18,    19,    70,    60,    58,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    66,    67,    68,    69,    70,    71,    72,   173,   103,
     104,   105,    49,    43,    79,    59,    60,    42,    43,    36,
      37,   186,    39,   188,     0,    42,    43,    61,    62,   189,
     106,    53,    26,    55,   199,    52,    33,    34,    35,    51,
      49,    53,    92,    33,    34,    49,    43,    44,    45,    46,
      47,    48,    95,    96,   101,   102,   121,   122,    22,    27,
     125,    49,    49,   128,    61,    62,   131,    66,    50,   134,
      67,    68,    69,    21,    35,    49,   126,    20,    51,    51,
      38,    67,    43,    44,    45,    46,    47,    48,   138,    50,
      53,    51,   138,    49,    43,   160,    49,    49,    52,   164,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    49,   181,    53,    51,    49,
     185,    43,    24,   173,   202,    29,    93,   176,   170,   168,
      -1,   169,    94,    84,    -1,    -1,   186,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,   199,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    36,    37,    -1,    39,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    49,    -1,    36,    37,
      -1,    39,    -1,    -1,    42,    43,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    43,    -1,    -1,    61,
      62,    33,    34,    35,    -1,    67,    68,    69,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    50,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    33,    34,    35,    -1,    67,    68,    69,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    50,    -1,
      -1,    -1,    54,    -1,    56,    57,    -1,    -1,    -1,    61,
      62,    33,    34,    35,    -1,    67,    68,    69,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    -1,    -1,    -1,    61,
      62,    33,    34,    35,    -1,    67,    68,    69,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    50,    -1,
      -1,    -1,    54,    -1,    56,    -1,    -1,    -1,    18,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    36,    37,    39,    42,
      43,    49,    72,    73,    74,    75,    76,    78,    85,   105,
      43,    33,    34,    35,    43,    44,    45,    46,    47,    48,
      50,    54,    56,    61,    62,    67,    68,    69,    85,    88,
      89,    91,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   104,    49,    88,    43,    18,    28,    29,    30,
      31,    32,    50,     0,    73,    49,    49,    43,    78,    22,
      83,    84,   100,   100,    70,   103,    88,    55,    88,    57,
      88,   100,    49,    26,    27,    25,    58,    23,    24,    59,
      60,    61,    62,    63,    64,    65,    66,   100,    33,    34,
      49,    50,    88,    88,    88,    88,    88,    88,    51,    86,
      88,    18,    19,    49,    88,    21,    49,    43,    50,   104,
      51,    53,    55,    90,    53,    57,    92,    67,    52,    74,
      79,    80,    94,    95,    96,    96,    97,    97,    97,    97,
      98,    98,    99,    99,    99,   100,    51,    81,   105,    51,
      53,    87,    88,    88,    20,    88,    79,    88,    88,    88,
      74,    38,    77,    49,    51,    43,    88,    49,    49,    88,
      51,    53,    90,    92,    80,    37,    49,    79,    49,    53,
      82,    87,    88,    88,    79,    79,    43,   105,    51,    49,
      82,    43,    79,    82,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    77,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    82,    82,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    95,    96,    96,
      96,    96,    96,    97,    97,    97,    98,    98,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     5,     5,     2,
       2,     3,     2,     1,     3,     3,     3,     3,     3,     3,
       5,     4,     5,     2,     1,     3,     5,     6,     6,     7,
       1,     1,     3,     2,     2,     3,     3,     2,     4,     3,
       4,     3,     1,     4,     3,     2,     1,     3,     2,     3,
       1,     1,     1,     3,     2,     3,     1,     3,     2,     3,
       1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     1,     3,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     2,     2,     2,     4,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (driver, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, driver); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, Driver driver)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (driver);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, Driver driver)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, driver);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, Driver driver)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , driver);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, driver); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, Driver driver)
{
  YYUSE (yyvaluep);
  YYUSE (driver);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (Driver driver)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 80 "grammar.y" /* yacc.c:1646  */
    { driver.finalizeTree(); }
#line 1487 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 84 "grammar.y" /* yacc.c:1646  */
    { driver.dumpStatement((yyvsp[-1].plane));	}
#line 1493 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "grammar.y" /* yacc.c:1646  */
    { driver.dumpStatement((yyvsp[0].plane));	}
#line 1499 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.createDecl((yyvsp[-2].i32val), (yyvsp[-1].str), A_NON, NULL);	}
#line 1505 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.createDecl((yyvsp[-4].i32val), (yyvsp[-3].str), A_REG, (yyvsp[-1].plane));	}
#line 1511 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.createDecl((yyvsp[-4].i32val), (yyvsp[-3].str), A_DEP, (yyvsp[-1].plane));	}
#line 1517 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[-1].plane);										}
#line 1523 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 94 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = NULL; /* TODO */							}
#line 1529 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 95 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = NULL; /* TODO */							}
#line 1535 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 96 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = NULL; /* TODO */							}
#line 1541 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = NULL; /* TODO */							}
#line 1547 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 139 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcArgDec((yyvsp[0].str), (yyvsp[-1].i32val), NULL);		}
#line 1553 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 140 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcArgDec((yyvsp[-1].str), (yyvsp[-2].i32val), (yyvsp[0].plane));		}
#line 1559 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 144 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcArgDec((yyvsp[-1].str), DT_NONE, (yyvsp[0].plane));	}
#line 1565 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 145 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcArgDec((yyvsp[0].str), DT_NONE, NULL);}
#line 1571 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 146 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcArgDec((yyvsp[-1].str), (yyvsp[-2].i32val), (yyvsp[0].plane));		}
#line 1577 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 147 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcArgDec((yyvsp[0].str), (yyvsp[-1].i32val), NULL);		}
#line 1583 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 151 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.fromTo((yyvsp[-2].plane), (yyvsp[0].plane));				}
#line 1589 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 155 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.fromToConstruct((yyvsp[-2].plane), (yyvsp[0].plane));		}
#line 1595 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 156 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.fromToConstruct((yyvsp[0].plane), NULL);	}
#line 1601 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 160 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcCall((yyvsp[-3].str), (yyvsp[-1].plane));		}
#line 1607 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 161 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcCall((yyvsp[-2].str), NULL);	}
#line 1613 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 165 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcArg((yyvsp[-1].plane), (yyvsp[0].plane));		}
#line 1619 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 166 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);							}
#line 1625 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 170 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.funcArg((yyvsp[-1].plane), (yyvsp[0].plane));		}
#line 1631 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 171 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);							}
#line 1637 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 175 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[-1].plane);							}
#line 1643 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 176 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);							}
#line 1649 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 177 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);							}
#line 1655 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 178 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);							}
#line 1661 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 182 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.abtSeq((yyvsp[-1].plane), (yyvsp[0].plane));		}
#line 1667 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 183 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.abtSeq(NULL, NULL);	}
#line 1673 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 187 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.abtSeq((yyvsp[-1].plane), (yyvsp[0].plane));		}
#line 1679 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 188 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = NULL;						}
#line 1685 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 192 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.abtSet((yyvsp[-1].plane), (yyvsp[0].plane));		}
#line 1691 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 193 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.abtSet(NULL, NULL);	}
#line 1697 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 197 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.abtSet((yyvsp[-1].plane), (yyvsp[0].plane));		}
#line 1703 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 198 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = NULL;						}
#line 1709 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 203 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.bex((yyvsp[-2].plane), (yyvsp[0].plane), N_BEX_ORR);	}
#line 1715 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 207 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);								}
#line 1721 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 208 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.bex((yyvsp[-2].plane), (yyvsp[0].plane), N_BEX_AND);	}
#line 1727 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 212 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);								}
#line 1733 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 213 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.bex((yyvsp[-2].plane), (yyvsp[0].plane), N_BEX_EQU);	}
#line 1739 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 214 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.bex((yyvsp[-2].plane), (yyvsp[0].plane), N_BEX_NEQ);	}
#line 1745 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 218 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);								}
#line 1751 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 219 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.bex((yyvsp[-2].plane), (yyvsp[0].plane), N_BEX_LES);	}
#line 1757 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 220 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.bex((yyvsp[-2].plane), (yyvsp[0].plane), N_BEX_GRT);	}
#line 1763 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 221 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.bex((yyvsp[-2].plane), (yyvsp[0].plane), N_BEX_LEQ);	}
#line 1769 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 222 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.bex((yyvsp[-2].plane), (yyvsp[0].plane), N_BEX_GEQ);	}
#line 1775 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 227 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.mathAdd((yyvsp[-2].plane), (yyvsp[0].plane));		}
#line 1781 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 228 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.mathSub((yyvsp[-2].plane), (yyvsp[0].plane));		}
#line 1787 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 233 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.mathMul((yyvsp[-2].plane), (yyvsp[0].plane));			}
#line 1793 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 234 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.mathDiv((yyvsp[-2].plane), (yyvsp[0].plane));			}
#line 1799 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 235 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.mathMod((yyvsp[-2].plane), (yyvsp[0].plane));			}
#line 1805 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 239 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);								}
#line 1811 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 240 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.mathPow((yyvsp[-2].plane), (yyvsp[0].plane));			}
#line 1817 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 244 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);								}
#line 1823 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 245 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.mathLen((yyvsp[-1].plane));				}
#line 1829 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 246 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.incDecOpt((yyvsp[0].plane), N_PRE_INC); }
#line 1835 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 247 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.incDecOpt((yyvsp[0].plane), N_PRE_DEC);	}
#line 1841 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 248 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.incDecOpt((yyvsp[0].plane), (yyvsp[-1].i32val));		}
#line 1847 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 252 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = N_UNI_DEP;						}
#line 1853 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 253 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = N_UNI_NEG;						}
#line 1859 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 254 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = N_UNI_POS;						}
#line 1865 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 255 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = N_UNI_LNG;						}
#line 1871 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 259 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);								}
#line 1877 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 260 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.index2((yyvsp[0].str));				}
#line 1883 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 261 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.indexing((yyvsp[-1].str), (yyvsp[0].plane));			}
#line 1889 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 262 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = (yyvsp[0].plane);								}
#line 1895 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 263 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.incDecOpt((yyvsp[-1].plane), N_PST_INC);	}
#line 1901 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 264 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.incDecOpt((yyvsp[-1].plane), N_PST_DEC);	}
#line 1907 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 268 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.indexOpt((yyvsp[0].plane), NULL);					}
#line 1913 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 269 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.indexOpt(driver.index2((yyvsp[0].str)), NULL);	}
#line 1919 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 270 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.indexOpt((yyvsp[-1].plane), NULL);					}
#line 1925 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 271 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.indexOpt((yyvsp[-3].plane), (yyvsp[-1].plane));						}
#line 1931 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 275 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.i32((yyvsp[0].i32val));	}
#line 1937 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 276 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.i64((yyvsp[0].i64val));	}
#line 1943 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 277 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.f32((yyvsp[0].f32val));	}
#line 1949 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 278 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.f64((yyvsp[0].f64val));	}
#line 1955 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 279 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.b((yyvsp[0].bval));	}
#line 1961 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 280 "grammar.y" /* yacc.c:1646  */
    { (yyval.plane) = driver.str((yyvsp[0].str)); printf("STR: %s\n", (yyvsp[0].str));  }
#line 1967 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 284 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_STR;	}
#line 1973 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 285 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_LIST;	}
#line 1979 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 286 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_SET;	}
#line 1985 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 287 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_I8;	}
#line 1991 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 288 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_I16;	}
#line 1997 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 289 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_I32;	}
#line 2003 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 290 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_I64;	}
#line 2009 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 291 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_UI8;	}
#line 2015 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 292 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_UI16;	}
#line 2021 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 293 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_UI32;	}
#line 2027 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 294 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_UI64;	}
#line 2033 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 295 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_F32;	}
#line 2039 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 296 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_F64;	}
#line 2045 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 297 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_BOOL;	}
#line 2051 "grammar.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 298 "grammar.y" /* yacc.c:1646  */
    { (yyval.i32val) = DT_VAR;	}
#line 2057 "grammar.tab.cpp" /* yacc.c:1646  */
    break;


#line 2061 "grammar.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (driver, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (driver, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, driver);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, driver);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (driver, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, driver);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, driver);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 301 "grammar.y" /* yacc.c:1906  */

/*
int main() {
    yyin = stdin;

    do {
        yyparse();
    } while (!feof(yyin));
    
    return 0;
}*/

