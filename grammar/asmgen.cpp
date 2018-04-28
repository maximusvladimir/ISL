#include "asmgen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUILT_COUNT	1

SymTable* masterTable;
Block* masterBlock;
Block* originMaster;
StrTable* stringTable;
const char* builtInFunctions[BUILT_COUNT] = {"printf"};
int blockIter;
int masterBlockCount;
int currReg;
int currStrRef;
int loopIterators;
int currLoopIterator;
FILE* output;

void debugDumpBlocks() {
	Block* b = masterBlock;
	printf("BLOCK #0\n");
	while (b != NULL) {
		Block* toPar = b->parentBlock;
		int tabs = 0;
		while (toPar != NULL) {
			tabs++;
			toPar = toPar->parentBlock;
		}
		int i;
		for (i = 0; i < tabs; i++) {
			printf("\t");
		}
		if (b != masterBlock) {
			printf("BLOCK #%d (parent #%d)\n", b->blockId, b->parentBlock->blockId);
		}
		b = b->next;
	}
}

void asmMov(int blockId, int reg, char* rightSide) {
	const char* ss = "";
	if (reg == R_EAX)
		ss = "eax";
	else if (reg == R_EBX)
		ss = "ebx";
	else if (reg == R_ECX)
		ss = "ecx";
	else if (reg == R_EDX)
		ss = "edx";
	else
		printf("ERROR: Unknown register selected!\n");
	fprintf(output, "\tmov %s, %s\n", ss, rightSide);
}

void traversePlaneForStrTable(Plane* p) {
	if (p == NULL)
		return;

	traverseListForStrTable(p->sub);
	traversePlaneForStrTable(p->left);
	traversePlaneForStrTable(p->right);

	if (p->type == DT_STR) {
		StrTable* tmp = (StrTable*)malloc(sizeof(StrTable));
		tmp->next = NULL;
		tmp->ref = currStrRef++;
		tmp->val = p->val.str;
		if (stringTable == NULL) {
			stringTable = tmp;
		} else {
			StrTable* next = stringTable;
			stringTable = tmp;
			stringTable->next = next;
		}
	} else if (p->type == N_FOR_STR) {
		loopIterators++;
	}
}

void traverseListForStrTable(LL* l) {
	if (l == NULL)
		return;

	traversePlaneForStrTable(l->value);
	traverseListForStrTable(l->next);
	traverseListForStrTable(l->sub);
}

void buildStringTable(LL* l) {
	stringTable = NULL;
	traverseListForStrTable(l);

	StrTable* curr = stringTable;
	while (curr != NULL) {
		fprintf(output, "STR%04d DB %s,0\n", curr->ref, curr->val);

		curr = curr->next;
	}
}

StrTable* getString(char* c) {
	StrTable* curr = stringTable;
	while (curr != NULL) {
		if (strcmp(curr->val, c) == 0) {
			return curr;
		}

		curr = curr->next;
	}
	
	printf("FATAL: Cannot find string. You should NEVER see this.\n");
	return curr;
}

void setupHeader(LL* l) {
	/*int i;
	for (i = 0; i < 16; i++) {
		fprintf(output, "tmpi32%02d\t\tdd\t0\n", i);
	}*/
	fprintf(output, "[BITS 32]\n");
	loopIterators = 0;
	currLoopIterator = 0;

	buildStringTable(l);

	int i;
	for (i = 0; i < loopIterators; i++) {
		fprintf(output, "iter%03d\t\tdd\t0\n", i);
	}

	fprintf(output, "\n");
}

void generateAsm(LL* l) {
	blockIter = 0;
	currReg = 0;
	currStrRef = 0;
	masterBlockCount = 0;
	output = fopen("output.asm", "w");
	setupHeader(l);

	masterBlock = (Block*)malloc(sizeof(Block));
	masterBlock->blockId = 0;
	masterBlock->parentBlock = masterBlock->next = NULL;
	originMaster = masterBlock;

	fprintf(output, ":main\n");

	LL* curr = l;
	while (curr != NULL) {
		Plane* stmt = curr->value;

		if (stmt->type >= 100 && stmt->type <= 200) {
			asmAssign(0, stmt);
		} else {
			switch (stmt->type) {
				case N_FUN_HED:
					declareFunction(stmt);
					break;
				case N_FUN_CAL:
					asmCallFunc(0, stmt);
					break;
				default:
					printf("blockid: %d, type: %d\n", 0, stmt->type);
					break;
			}
		}

		curr = curr->next;
	}

	debugDumpBlocks();
	
	fclose(output);
}

bool addToSymTable(int blockId, int type, char* ident) {
	int i;
	for (i = 0; i < BUILT_COUNT; i++) {
		if (strcmp(ident, builtInFunctions[i]) == 0) {
			return false;
		}
	}
	SymTable* c = (SymTable*)malloc(sizeof(SymTable));
	c->blockId = blockId;
	c->ident = ident;
	c->type = type;
	c->next = NULL;

	if (masterTable == NULL) {
		masterTable = c;
	} else {
		Block* myBlock = NULL;
		Block* curr = masterBlock;
		while (curr != NULL) {
			if (curr->blockId == blockId) {
				myBlock = curr;
				break;
			}
			curr = curr->next;
		}
		if (myBlock == NULL) {
			printf("FATAL: Cannot find the current block. We got lost in tree traversal.\n");
			exit(4);
		}

		Block* bst = myBlock;
		while (bst != NULL) {
			int currId = bst->blockId;

			SymTable* st = masterTable;
			while (st != NULL) {
				if (st->blockId == currId && strcmp(ident, st->ident) == 0) {
					free(c);
					return false;
				}
				st = st->next;
			}

			bst = bst->parentBlock;
		}

		// OKAY!
		SymTable* front = masterTable;
		masterTable = c;
		masterTable->next = front;
	}
	
	return true;
}

int asmGenExp(int blockId, Plane* stmt) {
	// TODO!
	if (stmt->type == DT_STR) {
		int reg = currReg++;
		StrTable* str = getString(stmt->val.str);
		fprintf(output, "\tmov r%d, STR%04d\n", reg, str->ref);
		return reg;
	}
	if (stmt->type == DT_I32) {
		int reg = currReg++;
		fprintf(output, "\tmov r%d, %d\n", reg, stmt->val.i32);
		return reg;
	}

	if (stmt->type >= N_MUL && stmt->type <= N_MOD) {
		int left = asmGenExp(blockId, stmt->left);
		int right = asmGenExp(blockId, stmt->right);
		// todo: protect EAX!
		fprintf(output, "\tmov eax, r%d\n", left);
		fprintf(output, "\tmov edx, r%d\n", right);
		//asmMov(blockId, R_EAX, "r%d
		switch (stmt->type) {
			case N_MUL:
				fprintf(output, "\tmul edx\n");
				break;
			case N_DIV:
				fprintf(output, "\tdiv edx\n");
				break;
			case N_ADD:
				fprintf(output, "\tadd edx\n");
				break;
			case N_SUB:
				fprintf(output, "\tsub edx\n");
				break;
			case N_MOD:
				fprintf(output, "\tmod edx\n");
				break;
		}
		int reg = currReg++;
		fprintf(output, "\tmov r%d, edx\n", reg);
		return reg;
	}

	if (stmt->type == N_FUN_CAL) {
		asmCallFunc(blockId, stmt);
		int reg = currReg++;
		fprintf(output, "\tmov r%d, eax\t\t\t; %s ret\n", reg, stmt->left->val.str);
		return reg;
	}

	if (stmt->type == N_IDEN) {
		// TODO: find the identifier in the symbol table.
		//fprintf(output, "\tmov r%d, e
	}

	printf("ERROR: %d general expression is unsupported at this time.\n", stmt->type);
	return 999999999;
}

void asmCallFunc(int blockId, Plane* stmt) {
	char* ident = stmt->left->val.str;
	Plane* args = stmt->right;
	//dumpStatement(args);
	while (args != NULL) {
		Plane* v = args;
		if (v->type == N_FUN_ARG) {
			v = v->left;
		}
		int reg = asmGenExp(blockId, v);
		fprintf(output, "\tpush r%d\n", reg);
		if (v->type == N_FUN_ARG) {
			args = args->right;
		} else {
			args = NULL;
		}
	}
	fprintf(output, "\tcall %s\n", ident);
}

void asmAssign(int blockId, Plane* stmt) {
	// the type of assignment is in stmt->type.
	if (stmt->left->type == N_DEC_VAR) {
		declareVar(blockId, stmt->left->left->val.i32, stmt->left->right->val.str);
		if (stmt->right != NULL) {
			int reg = asmGenExp(blockId, stmt->right);
			int mem = currReg++;//TODO: correctly point this to the right address or reg.
			fprintf(output, "\tmov [%d], r%d\t\t\t; [%d] = %s\n", mem, reg, mem, stmt->left->right->val.str);
		}
	} else {
		//dumpStatement(stmt);
		char* ident = stmt->left->val.str;
		int reg = asmGenExp(blockId, stmt->right);
		int mem = currReg++; // TODO: see if body.
		fprintf(output, "\tmov [%d], r%d\t\t\t; [%d] = %s\n", mem, reg, mem, ident);
		// assignment without decleration
	}
	//dumpStatement(stmt);
}

void handleSubBlock(Block* parentBlock, int blockId, LL* data) {
	Block* b = (Block*)malloc(sizeof(Block));
	b->blockId = blockId;
	b->parentBlock = parentBlock;
	b->next = NULL;

	Block* tmp = masterBlock;
	Block* prev = masterBlock;
	while (tmp != NULL) {
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = b;

	int oldReg = currReg;
	currReg = 0;
	LL* curr = data;
	while (curr != NULL) {
		Plane* stmt = curr->value;

		if (stmt->type >= 100 && stmt->type <= 200) {
			asmAssign(blockId, stmt);
		} else {
			switch (stmt->type) {
				case N_FUN_CAL:
					asmCallFunc(blockId, stmt);
					break;
				case N_FOR_STR:
					asmGenForeach(b, blockId, stmt);
				default:
					printf("blockid: %d, type: %d\n", blockId, stmt->type);
					break;
			}
		}

		curr = curr->next;
	}
	currReg = oldReg;
}

void declareVar(int blockId, int type, char* ident) {
	//printf("declaring variable %s, with type %d, in block %d\n", ident, type, blockId);
	if (!addToSymTable(blockId, type, ident)) {
		printf("FATAL: Could not declare %s: it has already been declared...\n", ident);
		exit(4);
	}
}

void asmGenForeach(Block* parentBlock, int blockId, Plane* stmt) {
	char* ident = stmt->left->val.str;
	int bi = ++blockIter;
	int claimed = currLoopIterator++;
	//declareVar(bi, DT_I32, ident);
	fprintf(output, "\tmov iter%03d, 0\n", claimed);
	fprintf(output, ":block%d\n", bi);
	//printf("%d\n", currLoopIterator);
	//printf("%d allowed\n", loopIterators);//fprintf(output, "iter%03d\t\tdd\t0\n", i);
	handleSubBlock(parentBlock, bi, stmt->sub);
	fprintf(output, "\tmov eax, 0\n");
	fprintf(output, "\tinc iter%03d\n", claimed);
	fprintf(output, "\tje block%d\n", bi);
	fprintf(output, "; end block %d\n", bi);
}

void declareFunction(Plane* funcHead) {
	Plane* t = funcHead->left;
	Plane* ident = funcHead->right->left;
	Plane* args = funcHead->right->right; // NULL WARNING!
	
	//printf("%s\n", ident->val.str);
	if (!addToSymTable(0, DT_FUNC, ident->val.str)) {
		printf("FATAL: %s has already been declared as a function. Overloading is not supported at this time.\n", ident->val.str);
		exit(4);
	} else {
		if (args == NULL) {
			// no arguments declared.
		} else {
			dumpStatement(args); // TODO
		}
		int bi = ++blockIter;
		fprintf(output, "\n:func%d\n", bi);
		handleSubBlock(originMaster, bi, funcHead->right->sub);
		fprintf(output, "\tret\n");
	}
}
















