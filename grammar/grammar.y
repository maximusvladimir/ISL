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
%token OPERATOR_ASSIGNMENT			30
%token OPERATOR_DEEP_ASSIGNMENT		31
%token OPERATOR_SET_TO				33
%token OPERATOR_SET_SKIP			34
%token OPERATOR_SET_FROM			35
%token OPERATOR_BOOL_LESS_OR_EQ		37
%token OPERATOR_BOOL_GREAT_OR_EQ	39
%token OPERATOR_BOOL_NEQ			41
%token OPERATOR_LOGICAL_OR			43
%token OPERATOR_LOGICAL_AND			44
%token OPERATOR_MULT_ASSIGN			53
%token OPERATOR_DIV_ASSIGN			54
%token OPERATOR_ADD_ASSIGN			55
%token OPERATOR_SUB_ASSIGN			56

// Other Single Symbols
%token SYM_STR_CHAR					67

// Keywords
%token KEY_FOR_LOOP					80
%token KEY_IF						81
//%token KEY_THEN					82
%token KEY_ELSE						83
%token KEY_RETURN					84
%token KEY_BREAK					85
%token KEY_WHILE					86
%token KEY_FUNC						87

// Others
%token IDENTIFIER					100
%token <i32val> INT_NUMBER			101
%token <i64val> I64_NUMBER			102
%token <f32val> F32_NUMBER			103
%token <f64val> F64_NUMBER			104
%token <bval> BOOL_NUMBER			105
%token TAB_BLOCK					107
%token NEW_LINE						108

%start program
%%

program
	: rootblock_list
	;

rootblock_list
	: function rootblock_list
	| statement rootblock_list
	| exp_or_loop_statement inner_block
	| empty
	;

function
	: return_type KEY_FUNC IDENTIFIER '(' vars ')' NEW_LINE block
	;

return_type
	: prim_type
	| empty
	;

vars
	: prim_func_type prim_func_type_tail
	| empty
	;

prim_func_type
	: prim_type IDENTIFIER
	;

prim_func_type_tail
	: ',' prim_type IDENTIFIER prim_func_type_tail
	| ',' prim_func_type_tail
	| empty
	;

block
	: '\t' statement '\n' block
	| TAB_BLOCK exp_or_loop_statement inner_block
	| empty
	;

inner_block
	: NEW_LINE TAB_BLOCK block
	| NEW_LINE TAB_BLOCK TAB_BLOCK KEY_BREAK NEW_LINE
	| empty
	;

statement
	: assignment_statement
	| function_call
	| KEY_RETURN var_exp_or_call
	| empty
	;

exp_or_loop_statement
	: KEY_FOR_LOOP IDENTIFIER OPERATOR_SET_FROM from
	| KEY_IF var_exp_or_call
	| KEY_WHILE var_exp_or_call
	;

skip
	: OPERATOR_SET_SKIP var_exp_or_call
	: empty
	;

from
	: var_exp_or_call OPERATOR_SET_TO var_exp_or_call skip
	;

assignment_statement
	: broad_type IDENTIFIER OPERATOR_ASSIGNMENT var_exp_or_call
	| broad_type IDENTIFIER OPERATOR_DEEP_ASSIGNMENT var_exp_or_call
	| prim_type IDENTIFIER
	;

function_call
	: IDENTIFIER '(' vars_call ')'
	;

vars_call
	: var_exp_or_call vars_call_tail
	| empty
	;

vars_call_tail
	: ',' vars_call
	;

var_ref
	: IDENTIFIER array_ref
	;

array_ref
	: '@' '(' array_ref_args ')'
	| '@' single_item_ref
	| empty
	;

// I don't know if assignment supported indexing is done yet (TODO ?)

array_ref_args
	: single_item_ref
	| single_item_ref ',' single_item_ref
	;

single_item_ref
	: var_ref
	| adv_exp
	;

set_def
	: '{' var_exp_or_call set_def_tail
	| '{' from '}'
	;

set_def_tail
	: ',' var_exp_or_call set_def_tail
	| '}'
	;

list_def
	: '['var_exp_or_call list_def_tail
	| '[' from ']'
	;

list_def_tail
	: ',' var_exp_or_call list_def_tail
	| ']'
	;

var_exp_or_call
	: set_def
	| list_def
	| single_item_ref
	;

bool_exp
	: sim_exp '<' sim_exp
	| sim_exp OPERATOR_BOOL_LESS_OR_EQ sim_exp
	| sim_exp '>' sim_exp
	| sim_exp OPERATOR_BOOL_GREAT_OR_EQ sim_exp
	| sim_exp '=' sim_exp
	| sim_exp OPERATOR_BOOL_NEQ sim_exp
	| sim_exp
	;

bool_parent
	: bool_exp OPERATOR_LOGICAL_AND bool_exp
	| bool_exp OPERATOR_LOGICAL_OR bool_exp
	| bool_exp
	;

adv_exp
	: bool_parent
	| sim_exp
	;

sim_exp
	: sim_exp '+' adv_exp
	| sim_exp '-' sim_exp
	| sim_term
	| adv_term
	;

adv_term
	: sim_term
	| list_def
	| set_def
	| string
	;

sim_term
	: sim_term '*' factor1
	| sim_term '/' factor1
	| factor1
	;

factor1
	: factor1 '%' factor2
	| factor2
	;

factor2
	: length '^' factor2
	| length
	;

length
	: '|' deepcopy '|'
	| deepcopy
	;

deepcopy
	: '~' multi_type
	| base
	;

multi_type
	: list_def
	| set_def
	| string
	| var_ref
	;

base
	: '!' bool_parent
	| '(' adv_exp ')'
	| function_call
	| var_ref
	| INT_NUMBER
	| I64_NUMBER
	| BOOL_NUMBER
	| F32_NUMBER
	| F64_NUMBER
	;

string
	: SYM_STR_CHAR
	;

broad_type
	: PRIM_TYPE_VAR
	| prim_type
	;

prim_type
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
	;

empty
	:
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
