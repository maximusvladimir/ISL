#include "strlib.h"

// S2 is cleaned up.
// S1 is returned. A seperate string is not created.
STR* str_concat(STR* s1, STR* s2) {
	int first_is_null = 0;
	STR_TAIL* curr = s1->next;
	if (curr == NULL) {
		first_is_null = 1;
	} else {
		while (1) {
			if (curr->next == NULL) {
				break;
			} else {
				curr = curr->next;
			}		
		}
	}

	STR_TAIL* neu = (STR_TAIL*)malloc(sizeof(STR_TAIL));
	neu->next = s2->next;
	neu->contents = s2->contents;
	neu->sub_length = s2->sub_length;
	
	s1->length += s2->length;
	if (first_is_null) {
		s1->next = neu;
	} else {
		curr->next = neu;
	}

	s2->next = NULL;
	s2->contents = NULL;
	free(s2);

	return s1;
}

// Same as str_concat, BUT a new string is created. S1 & S2 are cleaned up.
STR* str_concat_new(STR* s1, STR* s2) {
	STR* ns = str_debug_set("");
	ns = str_concat(ns, s1);
	ns = str_concat(ns, s2);

	str_free(s1);

	return ns;
}

unsigned long long ilog10c(unsigned long long v) {
	static const unsigned long long thr[64] = {
		10000000000000000000ULL, 0, 0, 0,	1000000000000000000ULL, 0, 0,	100000000000000000ULL, 0, 0,
			10000000000000000ULL, 0, 0, 0,		1000000000000000ULL, 0, 0,		100000000000000ULL, 0, 0,
				10000000000000ULL, 0, 0, 0,			1000000000000ULL, 0, 0,			100000000000ULL, 0, 0,
					10000000000ULL, 0, 0, 0,			1000000000ULL, 0, 0,			100000000ULL, 0, 0,
						10000000ULL, 0, 0, 0,				1000000ULL, 0, 0,				100000ULL, 0, 0,
							10000ULL, 0, 0, 0,					1000ULL, 0, 0,					100ULL, 0, 0,
								10ULL, 0, 0, 0
	};
	unsigned long long lz = __builtin_clzll(v);
	return (63 - lz) * 77 / 256 + (thr[lz] && v >= thr[lz]);
}

STR* str_concat_str_i64(STR* str, long long i) {
	if (i == 0) {
		return str_concat(str, str_debug_set("0"));
	}

	char tmp[21];
	tmp[0] = '-';
	long long num = i;
	num = num < 0 ? num * -1 : num;
	int digits = (int)ilog10c(num) + 1;
	int j = 0;
	while (num != 0) {
		int k = digits - j;
		if (i > 0) {
			k--;
		}
		tmp[k] = (num % 10) + '0';
		j++;
		num = num / 10;
	}
	
	return str_concat(str, str_debug_set(tmp));
}

STR* str_substr(STR* str, int index, int length) {
	if (length <= str->sub_length) {
		// fast lookup.
	}
}

// todo: substr.

void str_tail_free(STR_TAIL* s) {
	if (s->next != NULL) {
		str_tail_free(s->next);
		s->next = NULL;
	}
	free(s->contents);
	s->contents = NULL;
	free(s);
}

void str_free(STR* s1) {
	if (s1->next != NULL) {
		str_tail_free(s1->next);
	}
	
	free(s1->contents);
	s1->contents = NULL;
	free(s1);
}

void str_print(STR* str) {
	printf("%.*s", str->sub_length, str->contents);
	STR_TAIL* curr = str->next;
	while (1) {
		if (curr == NULL) {
			break;
		}
		printf("%.*s", curr->sub_length, curr->contents);
		curr = curr->next;
	}
}

unsigned int str_len(STR* str) {
	return str->length;
}

// Converts the linked list to a single string.
// Useful for calling external functions.
STR* str_defrag(STR* str) {
	if (str->next == NULL) {
		return str;
	}

	CHAR* big = (CHAR*)malloc(sizeof(CHAR) * str_len(str));
	int i = 0;
	for (i = 0; i < str->sub_length; i++) {
		big[i] = str->contents[i];
	}
	free(str->contents);
	STR_TAIL* curr = str->next;
	int local = 0;
	while (1) {
		for (local = 0; local < curr->sub_length; local++) {
			big[i++] = curr->contents[local];
		}

		STR_TAIL* last = curr;
		curr = curr->next;

		last->next = NULL;
		free(last->contents);
		last->contents = NULL;
		free(last);

		if (curr == NULL) {
			break;
		}
	}

	str->next = NULL;
	str->contents = big;
	str->sub_length = str->length;
	return str;
}

STR* str_debug_set(char* str) {
	STR* start = (STR*)malloc(sizeof(STR));
	start->length = strlen(str);
	start->sub_length = start->length;
	start->next = NULL;
	CHAR* c = (CHAR*)malloc(sizeof(CHAR) * start->length); // No \0 at the end.
	memcpy(c, str, start->length);
	start->contents = c;
	return start;
}







/*int main(int argc, char** argv) {
	STR* hi = str_debug_set("Hello world!");
	/*STR* bye = str_debug_set("\nGoodbye then.");
	STR* w = str_debug_set("\nWait actually I'm not done...");
	STR* abc = str_debug_set("ABC123 ");
	
	str_concat(hi, bye);
	str_concat(hi, w);
	hi = str_concat_new(abc, hi);

	printf("LENGTH: %d\n", str_len(hi));
	str_print(hi);

	STR* test = str_debug_set("Adding numbers: ");
	str_concat_str_i64(test, 22 * 54);
	str_print(test);

	str_free(test);
	str_free(hi);*

	printf("\n");
	return 0;
}*/







