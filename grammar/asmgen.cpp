#include "asmgen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUILT_COUNT	1

SymTable* masterTable;
const char* builtInFunctions[BUILT_COUNT] = {"printf"};
int blockIter;
int currReg;
FILE* output;

void setupMasterTable() {
	masterTable = (SymTable*)malloc(sizeof(SymTable));
	masterTable->blockID = 0;
	masterTable->next = NULL;
	masterTable->values = NULL;
}

void generateAsm(LL* l) {
	blockIter = 0;
	currReg = 0;
	output = fopen("output.asm", "w");
	setupMasterTable();

	LL* curr = l;
	while (curr != NULL) {
		Plane* stmt = curr->value;

		switch (stmt->type) {
			case N_FUN_HED:
				declareFunction(stmt);
				break;
			case N_FUN_CAL:
				asmCallFunc(0, stmt);
			default:
				printf("blockid: %d, type: %d\n", 0, stmt->type);
				break;
		}

		curr = curr->next;
	}

	fclose(output);
}

bool addToSymTable(int blockId, char* ident) {
	int i;
	for (i = 0; i < BUILT_COUNT; i++) {
		if (strcmp(ident, builtInFunctions[i]) == 0) {
			return false;
		}
	}
	SymTable* curr = masterTable;
	while (curr != NULL) {
		SLL* symList = curr->values;
		while (symList != NULL) {
			if (strcmp(ident, symList->current) == 0) {
				return false;
			}
		}

		// TODO: create tree to subverse sub tables.
		curr = NULL;
	}

	// TODO: pick appropriate table to add to:
	SymTable* addTo = masterTable;
	SLL* work = addTo->values;
	SLL* prev = NULL;
	while (work != NULL) {
		prev = work;
		work = work->next;
	}
	if (prev == NULL) {
		// root element.
		addTo->values = (SLL*)malloc(sizeof(SLL));
		addTo->values->next = NULL;
		addTo->values->current = ident;
	} else {
		// subsequent element.
		prev->next = (SLL*)malloc(sizeof(SLL));
		prev->next->next = NULL;
		prev->next->current = ident;
	}
	
	return true;
}

int asmGenExp(int blockId, Plane* stmt) {
	// TODO!
	if (stmt->type == DT_STR) {
		// TODO put in string table!
		int reg = currReg++;
		fprintf(output, "\tmov %d, %s\n", reg, stmt->val.str);
		return reg;
	}

	return -1;
}

void asmCallFunc(int blockId, Plane* stmt) {
	char* ident = stmt->left->val.str;
	Plane* args = stmt->right;
	while (args != NULL) {
		int reg = asmGenExp(blockId, args->left); // SEG FAULT!
		fprintf(output, "\tpush %d\n", reg);
		args = args->right;
	}
	fprintf(output, "\tcall %s\n", ident);
	dumpStatement(stmt);
}

void handleSubBlock(int blockId, LL* data) {
	int oldReg = currReg;
	currReg = 0;
	LL* curr = data;
	while (curr != NULL) {
		Plane* stmt = curr->value;

		switch (stmt->type) {
			case N_FUN_CAL:
				asmCallFunc(blockId, stmt);
				break;
			default:
				printf("blockid: %d, type: %d\n", blockId, stmt->type);
				break;
		}

		curr = curr->next;
	}
	currReg = oldReg;
}

void declareVar(int blockId, int type, char* ident) {
}

void declareFunction(Plane* funcHead) {
	Plane* t = funcHead->left;
	Plane* ident = funcHead->right->left;
	Plane* args = funcHead->right->right; // NULL WARNING!
	
	//printf("%s\n", ident->val.str);
	if (!addToSymTable(0, ident->val.str)) {
		printf("FATAL: %s has already been declared as a function. Overloading is not supported at this time.\n", ident->val.str);
		exit(4);
	} else {
		if (args == NULL) {
			// no arguments declared.
		} else {
			dumpStatement(args); // TODO
		}
		int bi = ++blockIter;
		fprintf(output, ":func%d\n", bi);
		handleSubBlock(bi, funcHead->right->sub);
	}
}










