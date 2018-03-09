%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern void yyerror(const char* s);
%}

%union {
	int i32val;
	long i64val;
	float f32val;
	double f64val;
	int bval;
}

%token PRIM_TYPE_STRING PRIM_TYPE_LIST PRIM_TYPE_SET PRIM_TYPE_I8 PRIM_TYPE_I16 
%token PRIM_TYPE_I32 PRIM_TYPE_I64 PRIM_TYPE_UI8 PRIM_TYPE_UI16 PRIM_TYPE_UI32 PRIM_TYPE_UI64 
%token PRIM_TYPE_F32 PRIM_TYPE_F64 PRIM_TYPE_BOOL PRIM_TYPE_VAR

// Operators
%token OPERATOR_ASSIGNMENT OPERATOR_DEEP_ASSIGNMENT OPERATOR_SET_TO OPERATOR_SET_SKIP OPERATOR_SET_FROM
%token OPERATOR_BOOL_LESS_OR_EQ OPERATOR_BOOL_GREAT_OR_EQ OPERATOR_BOOL_NEQ OPERATOR_LOGICAL_OR  OPERATOR_LOGICAL_AND
%token OPERATOR_MULT_ASSIGN OPERATOR_DIV_ASSIGN OPERATOR_ADD_ASSIGN OPERATOR_SUB_ASSIGN	OPERATOR_MOD_ASSIGN

// Other Single Symbols
%token SYM_STR_CHAR

// Keywords
%token KEY_FOR_LOOP KEY_IF KEY_ELSE KEY_RETURN KEY_BREAK KEY_WHILE KEY_FUNC

// Others
%token IDENTIFIER
%token <i32val> INT_NUMBER
%token <i64val> I64_NUMBER
%token <f32val> F32_NUMBER
%token <f64val> F64_NUMBER
%token <bval> BOOL_NUMBER

%start program
%%

program
	: rootblock_list
	;

rootblock_list
	: statement rootblock_list
	| statement
	| '\n'
	;

statement
	: var_type IDENTIFIER '\n' // PRIM_TYPE_VAR should NOT be allowed here. YACC isn't good at supporting this though.
	| var_type IDENTIFIER OPERATOR_ASSIGNMENT gen_exp '\n'
	| func_call '\n'
	| KEY_RETURN gen_exp '\n'
	| KEY_RETURN '\n'
	| block
	;

block
	: KEY_FOR_LOOP IDENTIFIER from_to '\n' sub_block
	| var_type func_head
	| func_head
	;

func_head
	: KEY_FUNC IDENTIFIER '(' ')' '\n' sub_block
	| KEY_FUNC IDENTIFIER '(' func_vars ')' '\n' sub_block
	;

sub_block
	: maybe_sub_block
	| statement
	;

maybe_sub_block
	: '\t' statement maybe_sub_block
	| '\t' statement
	;

func_vars
	: var_type IDENTIFIER
	| var_type IDENTIFIER func_vars_tail// PRIM_TYPE_VAR should NOT be allowed here. YACC isn't good at supporting this though.
	;

func_vars_tail
	: ',' IDENTIFIER func_vars_tail
	| ',' IDENTIFIER
	| ',' var_type IDENTIFIER func_vars_tail
	| ',' var_type IDENTIFIER
	;

from_to_base
	: OPERATOR_SET_FROM gen_exp OPERATOR_SET_TO gen_exp
	;

from_to
	: from_to_base OPERATOR_SET_SKIP gen_exp
	| from_to_base
	;

func_call
	: IDENTIFIER '(' func_arg_list ')'
	| IDENTIFIER '(' ')'
	;

func_arg_list
	: gen_exp func_arg_list_tail
	| gen_exp
	;

func_arg_list_tail
	: ',' gen_exp func_arg_list_tail
	| ',' gen_exp
	;

gen_exp
	: IDENTIFIER
	| INT_NUMBER
	| I64_NUMBER
	| F32_NUMBER
	| F64_NUMBER
	| BOOL_NUMBER
	| SYM_STR_CHAR
	| func_call
	;

math_exp
	: 

var_type
	: PRIM_TYPE_STRING
	| PRIM_TYPE_LIST
	| PRIM_TYPE_SET
	| PRIM_TYPE_I8
	| PRIM_TYPE_I16
	| PRIM_TYPE_I32
	| PRIM_TYPE_I64
	| PRIM_TYPE_UI8
	| PRIM_TYPE_UI16
	| PRIM_TYPE_UI32
	| PRIM_TYPE_UI64
	| PRIM_TYPE_F32
	| PRIM_TYPE_F64
	| PRIM_TYPE_BOOL
	| PRIM_TYPE_VAR
	;

%%
/*
int main() {
    yyin = stdin;

    do {
        yyparse();
    } while (!feof(yyin));
    
    return 0;
}*/

