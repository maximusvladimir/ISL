#include <stdio.h>

extern int yylex();
extern FILE* yyin;
extern FILE* yyout;

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
