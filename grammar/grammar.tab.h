/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
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
    PRIM_TYPE_STRING = 10,
    PRIM_TYPE_LIST = 11,
    PRIM_TYPE_SET = 12,
    PRIM_TYPE_I8 = 13,
    PRIM_TYPE_I16 = 14,
    PRIM_TYPE_I32 = 15,
    PRIM_TYPE_I64 = 16,
    PRIM_TYPE_UI8 = 17,
    PRIM_TYPE_UI16 = 18,
    PRIM_TYPE_UI32 = 19,
    PRIM_TYPE_UI64 = 20,
    PRIM_TYPE_F32 = 21,
    PRIM_TYPE_F64 = 22,
    PRIM_TYPE_BOOL = 23,
    PRIM_TYPE_VAR = 24,
    OPERATOR_ASSIGNMENT = 30,
    OPERATOR_DEEP_ASSIGNMENT = 31,
    OPERATOR_DEEP_COPY = 32,
    OPERATOR_SET_TO = 33,
    OPERATOR_SET_SKIP = 34,
    OPERATOR_SET_FROM = 35,
    OPERATOR_BOOL_LESS = 36,
    OPERATOR_BOOL_LESS_OR_EQ = 37,
    OPERATOR_BOOL_GREAT = 38,
    OPERATOR_BOOL_GREAT_OR_EQ = 39,
    OPERATOR_BOOL_EQ = 40,
    OPERATOR_BOOL_NEQ = 41,
    OPERATOR_BOOL_NEG = 42,
    OPERATOR_LOGICAL_OR = 43,
    OPERATOR_LOGICAL_AND = 44,
    OPERATOR_INDEX = 45,
    OPERATOR_MULT = 46,
    OPERATOR_DIV = 47,
    OPERATOR_ADD = 48,
    OPERATOR_SUB = 49,
    OPERATOR_POW = 50,
    OPERATOR_LENGTH = 51,
    OPERATOR_MOD = 52,
    OPERATOR_MULT_ASSIGN = 53,
    OPERATOR_DIV_ASSIGN = 54,
    OPERATOR_ADD_ASSIGN = 55,
    OPERATOR_SUB_ASSIGN = 56,
    SYM_DOUBLE_QUOTE = 60,
    SYM_SINGLE_QUOTE = 61,
    SYM_LIST_START = 62,
    SYM_LIST_END = 63,
    SYM_SET_START = 64,
    SYM_SET_END = 65,
    SYM_COMMA = 66,
    SYM_STR_CHAR = 67,
    SYM_PAR_OPEN = 68,
    SYM_PAR_CLOSE = 69,
    KEY_FOR_LOOP = 80,
    KEY_IF = 81,
    KEY_ELSE = 83,
    KEY_RETURN = 84,
    KEY_BREAK = 85,
    KEY_WHILE = 86,
    KEY_FUNC = 87,
    IDENTIFIER = 100,
    INT_NUMBER = 101,
    I64_NUMBER = 102,
    F32_NUMBER = 103,
    F64_NUMBER = 104,
    BOOL_TRUE = 105,
    BOOL_FALSE = 106,
    TAB_BLOCK = 107,
    NEW_LINE = 108
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
