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
#line 16 "grammar.y" /* yacc.c:1909  */

	int i32val;
	long i64val;
	float f32val;
	double f64val;
	int bval;
	char* str;
	Plane* plane;
	LL* list;

#line 114 "grammar.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (Driver driver);

#endif /* !YY_YY_GRAMMAR_TAB_HPP_INCLUDED  */
