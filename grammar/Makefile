all: isl

grammar.tab.c grammar.tab.h: grammar.y
	bison -d grammar.y

lex.yy.c: lexanalysis.l grammar.tab.h
	flex lexanalysis.l

isl: main.c lex.yy.c grammar.tab.c tree.c grammar.tab.h
	gcc -g -o isl grammar.tab.c lex.yy.c main.c tree.c

clean:
	rm isl lex.yy.c grammar.tab.c grammar.tab.h
