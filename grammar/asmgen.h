#ifndef __HEADER_ASMGEN
#define __HEADER_ASMGEN

#include "tree.h"

#define R_EAX	1
#define R_EBX	2
#define R_ECX	3
#define R_EDX	4

typedef struct StrTable {
	struct StrTable* next;
	char* val;
	int ref;
} StrTable;

typedef struct Block {
	int blockId;
	Block* parentBlock;
	Block* next;
} Block;

typedef struct SymTable {
	int blockId;
	char* ident;
	int type;
	SymTable* next;
} SymTable;

bool addToSymTable(int blockId, int type, char* ident);
void generateAsm(LL* prog);
void declareFunction(Plane* funcHead);
void handleSubBlock(Block* parentBlock, int blockId, LL* data);
void declareVar(int blockId, int type, char* ident);
void asmCallFunc(int blockId, Plane* stmt);
int asmGenExp(int blockId, Plane* stmt); // returns the current register the result of the gen exp is in.
void asmAssign(int blockId, Plane* stmt);
void asmMov(int blockId, int reg, char* rightSide);
void traversePlaneForStrTable(Plane* p);
void traverseListForStrTable(LL* l);
void buildStringTable(LL* l);
void setupHeader(LL* l);
void asmGenForeach(Block* parentBlock, int blockId, Plane* stmt);
StrTable* getString(char* c);


void debugDumpSymTable();
void debugDumpBlocks();

#endif
