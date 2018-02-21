## Compiling

1. Make sure BISON and FLEX are installed on your OS and in the system path.
2. Run ```bison -d grammar.y```. This generates the header type file and grammar file.
3. Run ```flex lexanalysis.l```. This will create the lexical anaylizer c file.
4. Run ```gcc lex.yy.c grammar.tab.c```
