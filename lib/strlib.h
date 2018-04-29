#ifndef __HEADER_STRLIB
#define __HEADER_STRLIB

#include "app.h"

#define CHAR char

typedef struct STR_TAIL {
	unsigned int sub_length;
	CHAR* contents;
	struct STR_TAIL* next;
	
	// Coming soon to own on video & DVD:
	//struct STR_TABLE_PTR table_loc;
} STR_TAIL;

typedef struct STR {
	unsigned int length;
	unsigned int sub_length;
	CHAR* contents;
	struct STR_TAIL* next;
} STR;

STR* str_concat(STR* s1, STR* s2);
STR* str_concat_str_i64(STR* str, long long i);
void str_free(STR* s1);
void str_print(STR* str);
unsigned int str_len(STR* str);
STR* str_defrag(STR* str);
STR* str_debug_set(char* str);
STR* str_concat_new(STR* s1, STR* s2);

#endif
