%{
#include <stdio.h>
#include "grammar.tab.h"
#include <inttypes.h>

//#define YY_DECL int yylex()

void comment();
void comment2();

void storebool(int b);
void storei32(char v[]);
void storei64(char v[]);
void storef32(char v[]);
void storef64(char v[]);

// use standard io for now:
//#define YY_STDINIT
%}

%option yylineno

%%
"/*"										{ comment(); }
(\t)*\/\/.*									{}

L?\"(\\.|[^\\"])*\"							return SYM_STR_CHAR;
L?\'(\\.|[^\\'])*\'							return SYM_STR_CHAR;

[ \v\f]										{}
[\r]*										{}
[\n]*										return '\n';
[\t]*										return '\t';
[    ]*										return '\t';

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
"~"											return '~';//return OPERATOR_DEEP_COPY;
"to"										return OPERATOR_SET_TO;
"skip"										return OPERATOR_SET_SKIP;
"from"										return OPERATOR_SET_FROM;
"<"											return '<';//OPERATOR_BOOL_LESS;
"<="										return OPERATOR_BOOL_LESS_OR_EQ;
">"											return '>';//return OPERATOR_BOOL_GREAT;
">="										return OPERATOR_BOOL_GREAT_OR_EQ;
"="											return '=';//OPERATOR_BOOL_EQ;
"!="										return OPERATOR_BOOL_NEQ;
"!"											return '!';//OPERATOR_BOOL_NEG;
"||"										return OPERATOR_LOGICAL_OR;
"&&"										return OPERATOR_LOGICAL_AND;
"@"											return '@';//OPERATOR_INDEX;
"*"											return '*';//return OPERATOR_MULT;
"*="										return OPERATOR_MULT_ASSIGN;
"/"											return '/';//return OPERATOR_DIV;
"/="										return OPERATOR_DIV_ASSIGN;
"+"											return '+';//OPERATOR_ADD;
"+="										return OPERATOR_ADD_ASSIGN;
"-"											return '-';//OPERATOR_SUB;
"-="										return OPERATOR_SUB_ASSIGN;
"^"											return '^';//OPERATOR_POW;
"|"											return '|';//OPERATOR_LENGTH;
"%"											return '%';//OPERATOR_MOD;
"%="										return OPERATOR_MOD_ASSIGN;
"\""										return '"';//SYM_DOUBLE_QUOTE;
"'"											return '\'';//SYM_SINGLE_QUOTE;
"["											return '[';//SYM_LIST_START;
"]"											return ']';//SYM_LIST_END;
"{"											return '{';//SYM_SET_START;
"}"											return '}';//SYM_SET_END;
","											return ',';//SYM_COMMA;
"("											return '(';//SYM_PAR_OPEN;
")"											return ')';//SYM_PAR_CLOSE;
"foreach"									return KEY_FOR_LOOP;
"if"										return KEY_IF;
"else"										return KEY_ELSE;
"return"									return KEY_RETURN;
"break"										return KEY_BREAK;
"while"										return KEY_WHILE;
"func"										return KEY_FUNC;
"true"										{ /*storebool(1);*/ return BOOL_NUMBER; }
"false"										{ /*storebool(0); */return BOOL_NUMBER; /*[ ]*										{}*/}
[0-9]+										{ return INT_NUMBER; }
[0-9]+l										{ return I64_NUMBER; }
([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+) 			{ /*storef32(yytext); */return F64_NUMBER; }
([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+)f			{ return F32_NUMBER; }
[a-zA-Z_][a-zA-Z_0-9]*						return IDENTIFIER;
.											{ printf("Undefined character detected in lexer.\n"); }

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

void comment2() {
	while (1) {
		if (input() == '\n')
			break;
	}
}

/*void storebool(int b)
{
	yylval.bval = b;
}

void storei32(char v[])
{
	int val = strtoimax()
	yylval.i32val = atoi()
}*/

void storei64(char v[]);
void storef32(char v[]);
void storef64(char v[]);



