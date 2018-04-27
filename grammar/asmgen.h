#ifndef __HEADER_ASMGEN
#define __HEADER_ASMGEN

#include "tree.h"

typedef struct SLL {
	struct SLL* next;
	char* current;
} SLL;

typedef struct SymTable {
	int blockID;
	SLL* values;
	SymTable* next;
} SymTable;

void setupMasterTable();
bool addToSymTable(int blockId, char* ident);
void generateAsm(LL* prog);
void declareFunction(Plane* funcHead);
void handleSubBlock(int blockId, LL* data);
void declareVar(int blockId, int type, char* ident);
void asmCallFunc(int blockId, Plane* stmt);
int asmGenExp(int blockId, Plane* stmt); // returns the current register the result of the gen exp is in.

#endif
