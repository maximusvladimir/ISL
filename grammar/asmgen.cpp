#include "asmgen.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUILT_COUNT		1
#define TMP_REG_COUNT	4

SymTable* masterTable;
Block* masterBlock;
Block* originMaster;
StrTable* stringTable;
const char* builtInFunctions[BUILT_COUNT] = {"printf"};
const char* tmpVars[4] = {"tmp0", "tmp1", "tmp2", "tmp3"};
int blockIter;
int masterBlockCount;
int currReg;
int currStrRef;
int loopIterators;
int currLoopIterator;
int currI32Var, countI32Var;
bool freeEAX, freeEBX, freeEDX;
bool freeTMP0, freeTMP1, freeTMP2, freeTMP3;
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
		loopIterators += 2;
	} else if (p->type >= 100 && p->type <= 200) {
		if (p->left != NULL && p->left->left != NULL) {
			int type = p->left->left->val.i32;
			// TODO: infer type by traversing right side of assignmnet.
			if (type == DT_VAR || type == DT_I32) { // make all VAR as I32 (for now)!
				//countI32Var++;
				fprintf(output, "%s:\t\tRESW\t1\n", p->left->right->val.str);
			}
			//printf("%d\n", type);
		}
		//countI32Var++;
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
		fprintf(output, "str%04d:\t\tDB\t%s,0\n", curr->ref, curr->val);

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
		fprintf(output, "ITR%04d:\t\tRESW\t1\n", i);
	}

	/*for (i = 0; i < countI32Var; i++) {
		fprintf(output, "i32%04d:\t\tresw\t1\n", i);
	}*/

	for (i = 0; i < TMP_REG_COUNT; i++) {
		fprintf(output, "TMP%04d:\t\tRESW\t1\n", i);
	}

	fprintf(output, "\n");
}

void generateAsm(LL* l) {
	blockIter = 0;
	currReg = 0;
	currStrRef = 0;
	masterBlockCount = 0;
	countI32Var = currI32Var = 0;
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

const char* map_reg(int num) {
	if (num == -2) {
		return "eax";
	} else if (num == -3) {
		return "ebx";
	} else if (num == -4) {
		return "edx";
	}
	return "???";
}

const char* get_tmp(int &n) {
	if (freeEAX) {
		n = - 2;
		return "eax";
	} else if (freeEBX) {
		n = -3;
		return "ebx";
	} else if (freeEDX) {
		n = -4;
		return "edx";
	} else if (freeTMP0) {
		n = -5;
		return "[TMP0000]";
	} else if (freeTMP1) {
		n = -6;
		return "[TMP0001]";
	} else if (freeTMP2) {
		n = -7;
		return "[TMP0002]";
	} else if (freeTMP3) {
		n = -8;
		return "[TMP0003]";
	}
	return "???";
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
/*		int reg = currReg++;
		fprintf(output, "\tmov r%d, %d\n", reg, stmt->val.i32);
		return reg;*/
		const char* reg = "???";
		int ret = -1;
		if (freeEAX) {
			freeEAX = false;
			reg = "eax";
			ret = -2;
		} else if (freeEBX) {
			freeEBX = false;
			reg = "ebx";
			ret = -3;
		} else if (freeEDX) {
			freeEDX = false;
			reg = "edx";
			ret = -4;
		} else {
			printf("WARN: No free register found!\n");
		}
		
		fprintf(output, "\tmov %s, %d\n", reg, stmt->val.i32);
		return ret;
	}

	if (stmt->type >= N_MUL && stmt->type <= N_MOD) {
		int left = asmGenExp(blockId, stmt->left);
		int right = asmGenExp(blockId, stmt->right);

		const char* reg_left = map_reg(left);
		const char* reg_right = map_reg(right);

		int tmp_var = 0;
		const char* tmp = "";

		switch (stmt->type) {
			case N_MUL:
				fprintf(output, "\timul %s, %s\n", reg_left, reg_right);
				break;
			case N_DIV:
				if (left != -2) {
					if (!freeEAX) {
						tmp = get_tmp(tmp_var);
						fprintf(output, "\tmov %s, eax\n", tmp);
					}
					fprintf(output, "\tmov eax, %s\n", reg_left);
				}
				fprintf(output, "\tidiv %s\n", reg_right);
				if (left != -2) {
					fprintf(output, "\tmov %s, eax\n", reg_left);
					if (!freeEAX) {
						fprintf(output, "\tmov eax, %s\n", tmp);
					}
				}
				break;
			case N_ADD:
				fprintf(output, "\tadd %s, %s\n", reg_left, reg_right);
				break;
			case N_SUB:
				fprintf(output, "\tsub %s, %s\n", reg_left, reg_right);
				break;
			case N_MOD:
				//fprintf(output, "\tmod edx\n");
				// easiest way is using idiv, but fastest is bit shifts.
				printf("Modulo is not supported at this time.\n");
				break;
		}
		if (right == -2) {
			freeEAX = true;
		} else if (right == -3) {
			freeEBX = true;
		} else if (right == -4) {
			freeEDX = true;
		}
		//int reg = currReg++;
		//fprintf(output, "\tmov r%d, edx\n", reg);
		return left;
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
		const char* reg = "???";
		int ret = -1;
		if (freeEAX) {
			freeEAX = false;
			reg = "eax";
			ret = -2;
		} else if (freeEBX) {
			freeEBX = false;
			reg = "ebx";
			ret = -3;
		} else if (freeEDX) {
			freeEDX = false;
			reg = "edx";
			ret = -4;
		} else {
			printf("WARN: No free register found!\n");
		}
		fprintf(output, "\tmov %s, [%s]\n", reg, stmt->val.str);
		return ret;
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
		const char* r = "???";
		if (reg == -2) {
			r = "eax";
		} else if (reg == -3) {
			r = "ebx";
		} else if (reg == -4) {
			r = "edx";
		}
		fprintf(output, "\tpush %s\n", r);
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
		int type = stmt->left->left->val.i32;
		declareVar(blockId, type, stmt->left->right->val.str);
		if (stmt->right != NULL) {
			int reg = asmGenExp(blockId, stmt->right);
			int mem = 999999999;
			//TODO: correctly point this to the right address or reg.
			/*if (type == DT_VAR || type == DT_I32) {
				mem = currI32Var++;
			}*/
			const char* r = "???";
			if (reg == -2) {
				r = "eax";
				freeEAX = true;
			} else if (reg == -3) {
				r = "ebx";
				freeEBX = true;
			} else if (reg == -4) {
				r = "edx";
				freeEDX = true;
			}
			fprintf(output, "\tmov [%s], %s\n", stmt->left->right->val.str, r);
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
	freeEAX = freeEBX = freeEDX = freeTMP0 = freeTMP1 = freeTMP2 = freeTMP3 = true;
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
	int claimed1 = currLoopIterator++;
	int claimed2 = currLoopIterator++;
	//declareVar(bi, DT_I32, ident);
	//fprintf(output, "\tmov ecx, [iter%03d]\n", claimed1);
	fprintf(output, "\tmov ecx, [itr%04d]\n", claimed1); // claimed 1 has the starting var in it.
	fprintf(output, "\tmov eax, [itr%04d]\n", claimed2);
	fprintf(output, "\tcmp ecx, eax\n");
	fprintf(output, "\tjge blockend%d\n", bi);
	fprintf(output, ":block%d\n", bi);
	fprintf(output, "\tmov ecx, [iter%03d]\n", claimed1); // claimed 1 has the starting var in it.
	//printf("%d\n", currLoopIterator);
	//printf("%d allowed\n", loopIterators);//fprintf(output, "iter%03d\t\tdd\t0\n", i);
	handleSubBlock(parentBlock, bi, stmt->sub);
	//fprintf(output, "\tmov eax, 0\n");
	fprintf(output, "\tinc ecx\n");//iter%03d\n", claimed);
	fprintf(output, "\tmov [itr%04d], ecx\n", claimed1);
	fprintf(output, "\tmov eax, [itr%04d]\n", claimed2);
	fprintf(output, "\tcmp ecx, eax\n");
	fprintf(output, "\tjl block%d\n", bi);
	fprintf(output, ":blockend%d\n", bi);
	//fprintf(output, "\tje block%d\n", bi);
	//fprintf(output, "; end block %d\n", bi);
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
		fprintf(output, "\n:func%d\t\t; %s\n", bi, ident->val.str);
		handleSubBlock(originMaster, bi, funcHead->right->sub);
		fprintf(output, "\tret\n");
	}
}
















