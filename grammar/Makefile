all: isl

grammar.tab.cpp grammar.tab.hpp: grammar.y
	bison -d grammar.y -o grammar.tab.cpp

lex.yy.c: lexanalysis.l grammar.tab.hpp
	flex lexanalysis.l

isl: main.cpp asmgen.cpp lex.yy.c grammar.tab.c tree.cpp grammar.tab.hpp asmgen.h tree.h
	g++ -g -o isl tree.cpp lex.yy.c grammar.tab.cpp asmgen.cpp main.cpp

clean:
	rm isl lex.yy.c grammar.tab.cpp grammar.tab.hpp
