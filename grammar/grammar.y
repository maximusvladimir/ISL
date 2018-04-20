%{
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern void yyerror(Driver d, char const* s);
%}

%parse-param { Driver driver }

%union {
	int i32val;
	long i64val;
	float f32val;
	double f64val;
	int bval;
	char* str;
	Plane* plane;
}

%token PRIM_TYPE_STRING PRIM_TYPE_LIST PRIM_TYPE_SET PRIM_TYPE_I8 PRIM_TYPE_I16 
%token PRIM_TYPE_I32 PRIM_TYPE_I64 PRIM_TYPE_UI8 PRIM_TYPE_UI16 PRIM_TYPE_UI32 PRIM_TYPE_UI64 
%token PRIM_TYPE_F32 PRIM_TYPE_F64 PRIM_TYPE_BOOL PRIM_TYPE_VAR

// Operators
%token OPERATOR_ASSIGNMENT OPERATOR_DEEP_ASSIGNMENT OPERATOR_SET_TO OPERATOR_SET_SKIP OPERATOR_SET_FROM
%token OPERATOR_BOOL_LESS_OR_EQ OPERATOR_BOOL_GREAT_OR_EQ OPERATOR_BOOL_NEQ OPERATOR_LOGICAL_OR  OPERATOR_LOGICAL_AND
%token OPERATOR_MULT_ASSIGN OPERATOR_DIV_ASSIGN OPERATOR_ADD_ASSIGN OPERATOR_SUB_ASSIGN	OPERATOR_MOD_ASSIGN
%token OPERATOR_INC OPERATOR_DEC

// Other Single Symbols
%token SYM_STR_CHAR

// Keywords
%token KEY_FOR_LOOP KEY_IF KEY_ELSE KEY_RETURN KEY_BREAK KEY_WHILE KEY_FUNC

// Others
%token <str>	IDENTIFIER
%token <i32val> INT_NUMBER
%token <i64val> I64_NUMBER
%token <f32val> F32_NUMBER
%token <f64val> F64_NUMBER
%token <bval>	BOOL_NUMBER

%type <plane>	constant
%type <plane>	index
%type <plane>	postfix_exp
%type <i32val>	unary_operator
%type <plane>	unary_exp
%type <plane>	pow_exp
%type <i32val>	var_type
%type <plane>	mult_math_exp
%type <plane>	add_math_exp
%type <plane>	bool_or_math_exp
%type <plane>	logiceq_or_math_exp
%type <plane>	logicand_or_math_exp
%type <plane>	logicor_or_math_exp
%type <plane>	list_def
%type <plane>	list_def_tail
%type <plane>	set_def
%type <plane>	set_def_tail
%type <plane>	gen_exp
%type <plane>	func_arg_list_tail
%type <plane>	func_arg_list
%type <plane>	func_call
%type <plane>	from_to
%type <plane>	from_to_base
%type <plane>	func_vars_tail
%type <plane>	func_vars
%type <plane>	statement

%start program
%%

program
	: rootblock_list { driver.finalizeTree(); }
	;

rootblock_list
	: statement rootblock_list									{ driver.dumpStatement($1);	}
	| statement													{ driver.dumpStatement($1);	}
	| '\n'
	;

statement
	: var_type IDENTIFIER '\n' 									{ $$ = driver.createDecl($1, $2, A_NON, NULL);	}
	| var_type IDENTIFIER OPERATOR_ASSIGNMENT gen_exp '\n'		{ $$ = driver.createDecl($1, $2, A_REG, $4);	}
	| var_type IDENTIFIER OPERATOR_DEEP_ASSIGNMENT gen_exp '\n'	{ $$ = driver.createDecl($1, $2, A_DEP, $4);	}
	| func_call '\n'											{ $$ = $1;										}
	| assign_update_statement '\n'								{ $$ = NULL; /* TODO */							}
	| KEY_RETURN gen_exp '\n'									{ $$ = NULL; /* TODO */							}
	| KEY_RETURN '\n'											{ $$ = NULL; /* TODO */							}
	| block														{ $$ = NULL; /* TODO */							}
	;

assign_update_statement
	: IDENTIFIER OPERATOR_ASSIGNMENT gen_exp
	| IDENTIFIER OPERATOR_MULT_ASSIGN gen_exp
	| IDENTIFIER OPERATOR_DIV_ASSIGN gen_exp
	| IDENTIFIER OPERATOR_ADD_ASSIGN gen_exp
	| IDENTIFIER OPERATOR_SUB_ASSIGN gen_exp
	| IDENTIFIER OPERATOR_MOD_ASSIGN gen_exp
	;

block
	: KEY_FOR_LOOP IDENTIFIER from_to '\n' sub_block
	| KEY_IF gen_exp '\n' sub_block
	| KEY_IF gen_exp '\n' sub_block else_chain
	| var_type func_head
	| func_head
	;

else_chain
	: KEY_ELSE '\n' sub_block
	| KEY_ELSE KEY_IF gen_exp '\n' sub_block
	| KEY_ELSE KEY_IF gen_exp '\n' sub_block else_chain
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
	: var_type IDENTIFIER								{ $$ = driver.funcArgDec($2, $1, NULL);		}
	| var_type IDENTIFIER func_vars_tail				{ $$ = driver.funcArgDec($2, $1, $3);		} // PRIM_TYPE_VAR should NOT be allowed here. YACC isn't good at supporting this though.
	;

func_vars_tail
	: ',' IDENTIFIER func_vars_tail						{ $$ = driver.funcArgDec($2, DT_NONE, $3);	}
	| ',' IDENTIFIER									{ $$ = driver.funcArgDec($2, DT_NONE, NULL);}
	| ',' var_type IDENTIFIER func_vars_tail			{ $$ = driver.funcArgDec($3, $2, $4);		}
	| ',' var_type IDENTIFIER							{ $$ = driver.funcArgDec($3, $2, NULL);		}
	;

from_to_base
	: OPERATOR_SET_FROM gen_exp OPERATOR_SET_TO gen_exp	{ $$ = driver.fromTo($2, $4);				}
	;

from_to
	: from_to_base OPERATOR_SET_SKIP gen_exp			{ $$ = driver.fromToConstruct($1, $3);		}
	| from_to_base										{ $$ = driver.fromToConstruct($1, NULL);	}
	;

func_call
	: IDENTIFIER '(' func_arg_list ')'	{ $$ = driver.funcCall($1, $3);		}
	| IDENTIFIER '(' ')'				{ $$ = driver.funcCall($1, NULL);	}
	;

func_arg_list
	: gen_exp func_arg_list_tail		{ $$ = driver.funcArg($1, $2);		}
	| gen_exp							{ $$ = $1;							}
	;

func_arg_list_tail
	: ',' gen_exp func_arg_list_tail	{ $$ = driver.funcArg($2, $3);		}
	| ',' gen_exp						{ $$ = $2;							}
	;

gen_exp
	: '(' gen_exp ')'			{ $$ = $2;							}
	| logicor_or_math_exp		{ $$ = $1;							}
	| list_def					{ $$ = $1;							}
	| set_def					{ $$ = $1;							}
	;
	
list_def
	: '[' gen_exp list_def_tail	{ $$ = driver.abtSeq($2, $3);		}
	| '[' ']'					{ $$ = driver.abtSeq(NULL, NULL);	}
	;

list_def_tail
	: ',' gen_exp list_def_tail	{ $$ = driver.abtSeq($2, $3);		}
	| ']'						{ $$ = NULL;						}
	;

set_def
	: '{' gen_exp set_def_tail	{ $$ = driver.abtSet($2, $3);		}
	| '{' '}'					{ $$ = driver.abtSet(NULL, NULL);	}
	;

set_def_tail
	: ',' gen_exp set_def_tail	{ $$ = driver.abtSet($2, $3);		}
	| '}'						{ $$ = NULL;						}
	;

logicor_or_math_exp
	: logicand_or_math_exp
	| logicor_or_math_exp OPERATOR_LOGICAL_OR logicand_or_math_exp	{ $$ = driver.bex($1, $3, N_BEX_ORR);	}
	;

logicand_or_math_exp
	: logiceq_or_math_exp											{ $$ = $1;								}
	| logicand_or_math_exp OPERATOR_LOGICAL_AND logiceq_or_math_exp	{ $$ = driver.bex($1, $3, N_BEX_AND);	}
	;

logiceq_or_math_exp
	: bool_or_math_exp											{ $$ = $1;								}
	| logiceq_or_math_exp '=' bool_or_math_exp					{ $$ = driver.bex($1, $3, N_BEX_EQU);	}
	| logiceq_or_math_exp OPERATOR_BOOL_NEQ bool_or_math_exp	{ $$ = driver.bex($1, $3, N_BEX_NEQ);	}
	;

bool_or_math_exp
	: add_math_exp												{ $$ = $1;								}
	| bool_or_math_exp '<' add_math_exp							{ $$ = driver.bex($1, $3, N_BEX_LES);	}
	| bool_or_math_exp '>' add_math_exp							{ $$ = driver.bex($1, $3, N_BEX_GRT);	}
	| bool_or_math_exp OPERATOR_BOOL_LESS_OR_EQ add_math_exp	{ $$ = driver.bex($1, $3, N_BEX_LEQ);	}
	| bool_or_math_exp OPERATOR_BOOL_GREAT_OR_EQ add_math_exp	{ $$ = driver.bex($1, $3, N_BEX_GEQ);	}
	;

add_math_exp
	: mult_math_exp
	| add_math_exp '+' mult_math_exp { $$ = driver.mathAdd($1, $3);		}
	| add_math_exp '-' mult_math_exp { $$ = driver.mathSub($1, $3);		}
	;

mult_math_exp
	: pow_exp
	| mult_math_exp '*' pow_exp	{ $$ = driver.mathMul($1, $3);			}
	| mult_math_exp '/' pow_exp	{ $$ = driver.mathDiv($1, $3);			}
	| mult_math_exp '%' pow_exp	{ $$ = driver.mathMod($1, $3);			}
	;
	
pow_exp
	: unary_exp					{ $$ = $1;								}
	| pow_exp '^' unary_exp		{ $$ = driver.mathPow($1, $3);			}
	;

unary_exp
	: postfix_exp				{ $$ = $1;								}
	| '|' unary_exp '|'			{ $$ = driver.mathLen($2);				}
	| OPERATOR_INC unary_exp	{ $$ = driver.incDecOpt($2, N_PRE_INC); }
	| OPERATOR_DEC unary_exp	{ $$ = driver.incDecOpt($2, N_PRE_DEC);	}
	| unary_operator unary_exp	{ $$ = driver.incDecOpt($2, $1);		}
	;

unary_operator
	: '~'						{ $$ = N_UNI_DEP;						}
	| '-'						{ $$ = N_UNI_NEG;						}
	| '+'						{ $$ = N_UNI_POS;						} 
	| '!'						{ $$ = N_UNI_LNG;						}
	;

postfix_exp
	: func_call					{ $$ = $1;								}
	| IDENTIFIER				{ $$ = driver.index2($1);				}
	| IDENTIFIER index			{ $$ = driver.index2($1); /* TODO */	}
	| constant					{ $$ = $1;								}
	| postfix_exp OPERATOR_INC	{ $$ = driver.incDecOpt($1, N_PST_INC);	}
	| postfix_exp OPERATOR_DEC	{ $$ = driver.incDecOpt($1, N_PST_DEC);	}
	;
	
index
	: '@' constant						{ $$ = driver.index1($2); }
	| '@' IDENTIFIER					{ $$ = driver.index2($2); }
	| '@' '(' gen_exp ')'				{ $$ = NULL; noImplement("Array indexing");	} // skip for now.
	| '@' '(' gen_exp ',' gen_exp ')'	{ $$ = NULL; noImplement("Array indexing");	}
	;

constant
	: INT_NUMBER	{ $$ = driver.i32($1);	}
	| I64_NUMBER	{ $$ = driver.i64($1);	}
	| F32_NUMBER	{ $$ = driver.f32($1);	}
	| F64_NUMBER	{ $$ = driver.f64($1);	}
	| BOOL_NUMBER	{ $$ = driver.b($1);	}
	| SYM_STR_CHAR 	{ $$ = NULL;/*$$ = driver.str($1);*/  }// move to add only
	;

var_type
	: PRIM_TYPE_STRING	{ $$ = DT_STR;	}
	| PRIM_TYPE_LIST	{ $$ = DT_LIST;	}
	| PRIM_TYPE_SET		{ $$ = DT_SET;	}
	| PRIM_TYPE_I8		{ $$ = DT_I8;	}
	| PRIM_TYPE_I16		{ $$ = DT_I16;	}
	| PRIM_TYPE_I32		{ $$ = DT_I32;	}
	| PRIM_TYPE_I64		{ $$ = DT_I64;	}
	| PRIM_TYPE_UI8		{ $$ = DT_UI8;	}
	| PRIM_TYPE_UI16	{ $$ = DT_UI16;	}
	| PRIM_TYPE_UI32	{ $$ = DT_UI32;	}
	| PRIM_TYPE_UI64	{ $$ = DT_UI64;	}
	| PRIM_TYPE_F32		{ $$ = DT_F32;	}
	| PRIM_TYPE_F64		{ $$ = DT_F64;	}
	| PRIM_TYPE_BOOL	{ $$ = DT_BOOL;	}
	| PRIM_TYPE_VAR		{ $$ = DT_VAR;	}
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

