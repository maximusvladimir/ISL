%union {
	int i32val;
	long i64val;
	float f32val;
	double f64val;
	int bval;
}

%token PRIM_TYPE_STRING				10
%token PRIM_TYPE_LIST				11
%token PRIM_TYPE_SET				12
%token PRIM_TYPE_I8					13
%token PRIM_TYPE_I16				14
%token PRIM_TYPE_I32				15
%token PRIM_TYPE_I64				16
%token PRIM_TYPE_UI8				17
%token PRIM_TYPE_UI16				18
%token PRIM_TYPE_UI32				19
%token PRIM_TYPE_UI64				20
%token PRIM_TYPE_F32				21
%token PRIM_TYPE_F64				22
%token PRIM_TYPE_BOOL				23
%token PRIM_TYPE_VAR				24

// Operators
%token OPERATOR_ASSIGNMENT			30
%token OPERATOR_DEEP_ASSIGNMENT	31
%token OPERATOR_DEEP_COPY			32
%token OPERATOR_SET_TO				33
%token OPERATOR_SET_SKIP			34
%token OPERATOR_SET_FROM			35
%token OPERATOR_BOOL_LESS			36
%token OPERATOR_BOOL_LESS_OR_EQ		37
%token OPERATOR_BOOL_GREAT			38
%token OPERATOR_BOOL_GREAT_OR_EQ	39
%token OPERATOR_BOOL_EQ				40
%token OPERATOR_BOOL_NEQ			41
%token OPERATOR_BOOL_NEG			42
%token OPERATOR_LOGICAL_OR			43
%token OPERATOR_LOGICAL_AND			44
%token OPERATOR_INDEX				45
%token OPERATOR_MULT				46
%token OPERATOR_DIV					47
%token OPERATOR_ADD					48
%token OPERATOR_SUB					49
%token OPERATOR_POW					50
%token OPERATOR_LENGTH				51
%token OPERATOR_MOD					52
%token OPERATOR_MULT_ASSIGN			53
%token OPERATOR_DIV_ASSIGN			54
%token OPERATOR_ADD_ASSIGN			55
%token OPERATOR_SUB_ASSIGN			56

// Other Single Symbols
%token SYM_DOUBLE_QUOTE				60
%token SYM_SINGLE_QUOTE				61
%token SYM_LIST_START				62
%token SYM_LIST_END					63
%token SYM_SET_START				64
%token SYM_SET_END					65
%token SYM_COMMA					66
%token SYM_STR_CHAR					67
%token SYM_PAR_OPEN					68
%token SYM_PAR_CLOSE				69

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
	: statement rootblock_list
	: exp_or_loop_statement inner_block
	: empty
	;

function
	: return_type KEY_FUNC IDENTIFIER SYM_PAR_OPEN vars SYM_PAR_CLOSE NEW_LINE block
	;

return_type
	: prim_type
	: empty
	;

vars
	: prim_func_type prim_func_type_tail
	: empty
	;

prim_func_type
	: prim_type IDENTIFIER
	;

prim_func_type_tail
	: SYM_COMMA prim_type IDENTIFIER prim_func_type_tail
	: SYM_COMMA prim_func_type_tail
	: empty
	;

block
	: TAB_BLOCK statement NEW_LINE block
	: TAB_BLOCK exp_or_loop_statement inner_block
	: empty
	;

inner_block
	: NEW_LINE TAB_BLOCK block
	: NEW_LINE TAB_BLOCK TAB_BLOCK KEY_BREAK NEW_LINE
	: empty
	;

statement
	: assignment_statement
	: function_call
	: KEY_RETURN var_exp_or_call
	: empty
	;

exp_or_loop_statement
	: KEY_FOR_LOOP IDENTIFIER OPERATOR_SET_FROM from
	: KEY_IF var_exp_or_call
	: KEY_WHILE var_exp_or_call
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
	: broad_type IDENTIFIER OPERATOR_DEEP_ASSIGNMENT var_exp_or_call
	: prim_type IDENTIFIER
	;

function_call
	: IDENTIFIER SYM_PAR_OPEN vars_call SYM_PAR_CLOSE
	;

vars_call
	: var_exp_or_call vars_call_tail
	: empty
	;

vars_call_tail
	: SYM_COMMA vars_call
	;

var_ref
	: IDENTIFIER array_ref
	;

array_ref
	: OPERATOR_INDEX SYM_PAR_OPEN array_ref_args SYM_PAR_CLOSE
	: OPERATOR_INDEX single_item_ref
	: empty
	;

// I don't know if assignment supported indexing is done yet (TODO ?)

array_ref_args
	: single_item_ref
	: single_item_ref SYM_COMMA single_item_ref
	;

single_item_ref
	: var_ref
	: adv_ref
	;

set_def
	: SYM_SET_START var_exp_or_call set_def_tail
	: SYM_SET_START from SYM_SET_END
	;

set_def_tail
	: SYM_COMMA var_exp_or_call set_def_tail
	: SYM_SET_END
	;

list_def
	: SYM_LIST_START var_exp_or_call list_def_tail
	: SYM_LIST_START from SYM_LIST_END
	;

list_def_tail
	: SYM_COMMA var_exp_or_call list_def_tail
	: SYM_LIST_END
	;

var_exp_or_call
	: set_def
	: list_def
	: single_item_ref
	;

bool_exp
	: sim_exp OPERATOR_BOOL_LESS sim_exp
	: sim_exp OPERATOR_BOOL_LESS_OR_EQ sim_exp
	: sim_exp OPERATOR_BOOL_GREAT sim_exp
	: sim_exp OPERATOR_BOOL_GREAT_OR_EQ sim_exp
	: sim_exp OPERATOR_BOOL_EQ sim_exp
	: sim_exp OPERATOR_BOOL_NEQ sim_exp
	: sim_exp
	;

bool_parent
	: bool_exp OPERATOR_LOGICAL_AND bool_exp
	: bool_exp OPERATOR_LOGICAL_OR bool_exp
	: bool_exp
	;

adv_exp
	: bool_parent
	: sim_exp
	;

sim_exp
	: sim_exp OPERATOR_ADD adv_exp
	: sim_exp OPERATOR_SUB sim_exp
	: sim_term
	: adv_term
	;

adv_term
	: sim_term
	: list_def
	: set_def
	: string
	;

sim_term
	: sim_term OPERATOR_MULT factor1
	: sim_term OPERATOR_DIV factor1
	: factor1
	;

factor1
	: factor1 OPERATOR_MOD factor2
	: factor2
	;

factor2
	: length OPERATOR_POW factor2
	: length
	;

length
	: OPERATOR_LENGTH deepcopy OPERATOR_LENGTH
	: deepcopy
	;

deepcopy
	: OPERATOR_DEEP_COPY multi_type
	: base
	;

multi_type
	: list_def
	: set_def
	: string
	: var_def
	;

base
	: INT_NUMBER
	: I64_NUMBER
	: BOOL_NUMBER
	: F32_NUMBER
	: F64_NUMBER
	: OPERATOR_BOOL_NEG bool_parent
	: SYM_PAR_OPEN adv_exp SYM_PAR_CLOSE
	: function_call
	: var_ref
	;

string
	: SYM_STR_CHAR
	;

broad_type
	: PRIM_TYPE_VAR
	: prim_type
	;

prim_type
	: PRIM_TYPE_STRING
	: PRIM_TYPE_LIST
	: PRIM_TYPE_SET
	: PRIM_TYPE_I8
	: PRIM_TYPE_I16
	: PRIM_TYPE_I32
	: PRIM_TYPE_I64
	: PRIM_TYPE_UI8
	: PRIM_TYPE_UI16
	: PRIM_TYPE_UI32
	: PRIM_TYPE_UI64
	: PRIM_TYPE_F32
	: PRIM_TYPE_F64
	: PRIM_TYPE_BOOL
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
