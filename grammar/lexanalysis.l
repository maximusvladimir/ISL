%{
#include <stdio.h>
#include "gtype.h"

void comment();

// use standard io for now:
//#define YY_STDINIT
%}

%%
"/*"										{ comment(); }
"//".*										{}

L?\"(\\.|[^\\"])*\"							return SYM_STR_CHAR;
L?\'(\\.|[^\\'])*\'							return SYM_STR_CHAR;

"string"									return PRIM_TYPE_STRING;
"list"										return PRIM_TYPE_LIST;
"set"										return PRIM_TYPE_SET;
"i8"										return PRIM_TYPE_I8;
"i16"										return PRIM_TYPE_I16;
"i32"										return PRIM_TYPE_I32;
"i64"										return PRIM_TYPE_I64;
"ui8"										return PRIM_TYPE_UI8;
"ui16"										return PRIM_TYPE_UI16;
"ui32"										return PRIM_TYPE_UI32;
"ui64"										return PRIM_TYPE_UI64;
"f32"										return PRIM_TYPE_F32;
"f64"										return PRIM_TYPE_F64;
"bool"										return PRIM_TYPE_BOOL;
"var"										return PRIM_TYPE_VAR;
":="										return OPERATOR_ASSIGNMENT;
":~"										return OPERATOR_DEEP_ASSIGNMENT;
"~"											return OPERATOR_DEEP_COPY;
"to"										return OPERATOR_SET_TO;
"skip"										return OPERATOR_SET_SKIP;
"from"										return OPERATOR_SET_FROM;
"<"											return OPERATOR_BOOL_LESS;
"<="										return OPERATOR_BOOL_LESS_OR_EQ;
">"											return OPERATOR_BOOL_GREAT;
">="										return OPERATOR_BOOL_GREAT_OR_EQ;
"="											return OPERATOR_BOOL_EQ;
"!="										return OPERATOR_BOOL_NEQ;
"!"											return OPERATOR_BOOL_NEG;
"||"										return OPERATOR_LOGICAL_OR;
"&&"										return OPERATOR_LOGICAL_AND;
"@"											return OPERATOR_INDEX;
"*"											return OPERATOR_MULT;
"*="										return OPERATOR_MULT_ASSIGN;
"/"											return OPERATOR_DIV;
"/="										return OPERATOR_DIV_ASSIGN;
"+"											return OPERATOR_ADD;
"+="										return OPERATOR_ADD_ASSIGN;
"-"											return OPERATOR_SUB;
"-="										return OPERATOR_SUB_ASSIGN;
"^"											return OPERATOR_POW;
"|"											return OPERATOR_LENGTH;
"%"											return OPERATOR_MOD;
"\""										return SYM_DOUBLE_QUOTE;
"'"											return SYM_SINGLE_QUOTE;
"["											return SYM_LIST_START;
"]"											return SYM_LIST_END;
"{"											return SYM_SET_START;
"}"											return SYM_SET_END;
","											return SYM_COMMA;
"("											return SYM_PAR_OPEN;
")"											return SYM_PAR_CLOSE;
"foreach"									return KEY_FOR_LOOP;
"if"										return KEY_IF;
"else"										return KEY_ELSE;
"return"									return KEY_RETURN;
"break"										return KEY_BREAK;
"while"										return KEY_WHILE;
"func"										return KEY_FUNC;
"true"										return BOOL_TRUE;
"false"										return BOOL_FALSE;
[\t]										return TAB_BLOCK;
[\n]										return NEW_LINE;
[ \v\f]										{}
[ ]*										{}
[0-9]+										{ return INT_NUMBER; }
[0-9]+l										return I64_NUMBER;
([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+) 			return F64_NUMBER;
([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+)f			return F32_NUMBER;
[a-zA-Z_][a-zA-Z_0-9]*						return IDENTIFIER;

%%

int yywrap()
{
	return 1;
}

void comment()
{
	char c, c1;

	int cont = 1;
	
	while (cont)
	{
		cont = 0;
		while ((c = input()) != '*' && c != 0);
			//putchar(c);

		if ((c1 = input()) != '/' && c != 0)
		{
			//unput(c1);
			cont = 1;
		}
	}

	if (c != 0);
		//putchar(c1);
}	

int main(int argc, const char* argv[])
{
	if (argc == 1) {
		int ntoken, vtoken;
		printf("No input file selected. Reading from STDIN.\n");
		ntoken = yylex();
		while (ntoken)
		{
			printf("%d\n", ntoken);
			ntoken = yylex();
		}
	} else {
		FILE* fPtr = fopen(argv[1], "r");
		if (fPtr == NULL) {
			printf("Failed to open file \"%s\". Terminating.\n", argv[1]);
		} else {
			yyin = fPtr;
			yyout = stdout;
			int ntoken;
			while (1) {
				ntoken = yylex();
				if (ntoken == 0)
					break;
				if (ntoken != 108) {
					printf("%d ", ntoken);
				} else {
					printf("\n");
				}
			}
		}
	}

	return 0;
}



