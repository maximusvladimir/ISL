#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

extern void yyparse(Driver d);
extern FILE* yyin;
extern FILE* yyout;
extern int yylineno;

FILE* fPtr;
int usingFile;

void yyerror(Driver d, char const* s)
{
	fprintf(stderr, "Parse error: %s. Line #%d\n", s, yylineno);
	if (usingFile) {
		fseek(fPtr, 0, SEEK_SET);

		char* line = NULL;
		size_t len = 0;
		ssize_t read;
		int counter = 1;
		while ((read = getline(&line, &len, fPtr)) != -1) {
			if (yylineno == counter) {
			    printf("Contents of line: \"%.*s\".\n", (int)strlen(line) - 1, line);
				break;
			}

			counter++;
		}
	}
	
	exit(1);
}

int main(int argc, const char* argv[])
{
	Driver d;
	if (argc == 1) {
		usingFile = 0;
		int ntoken, vtoken;
		fprintf(stderr, "No input file selected. Reading from STDIN.\n");
		yyin = stdin;
		while (!feof(yyin))
		{
			yyparse(d);
		}
	} else {
		usingFile = 1;
		fPtr = fopen(argv[1], "r");
		if (fPtr == NULL) {
			printf("Failed to open file \"%s\". Terminating.\n", argv[1]);
		} else {
			yyin = fPtr;
			yyout = stdout;
			int ntoken;
			while (!feof(yyin)) {
				yyparse(d);
			}
		}
		printf("Finished parsing input file.\n");
	}

	return 0;
}
