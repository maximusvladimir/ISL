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
%token OPERATOR_ASSIGNMENT			30
%token OPERATOR_DEEP_ASSIGNMENT		31
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
%token KEY_FOR_LOOP					80
%token KEY_IF						81
%token KEY_ELSE						83
%token KEY_RETURN					84
%token KEY_BREAK					85
%token KEY_WHILE					86
%token KEY_FUNC						87
%token IDENTIFIER					100
%token INT_NUMBER					101
%token I64_NUMBER					102
%token F32_NUMBER					103
%token F64_NUMBER					104
%token BOOL_TRUE					105
%token BOOL_FALSE					106
%token TAB_BLOCK					107
%token NEW_LINE						108

%start primary_expression
%%

primary_expression
	: IDENTIFIER
	| INT_NUMBER
	| I64_NUMBER
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
