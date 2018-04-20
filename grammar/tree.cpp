#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

stack<Plane*> s;
int REG_COUNT;

void assertStack(int n) {
    if (s.size() < n) {
        printf("ERR: Expected at least 2 elements on stack.\n");
    }
}

Plane* setupPlane(int type) {
    Plane* p = (Plane*)malloc(sizeof(Plane));
    p->type = type;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Driver::Driver() {
    REG_COUNT = 0;
}

Plane* Driver::createDecl(int type2, char* ident, int a_type, Plane* right_side) {
    Plane* id = setupPlane(N_IDEN);
    id->val.str = ident;

    Plane* type = setupPlane(N_DEC_DEC);
    type->val.i32 = type2;

    Plane* i = setupPlane(N_DEC_VAR);
    i->left = type;
    i->right = id;

    Plane* r = setupPlane(a_type);
    r->left = i;
    r->right = right_side;

    return r;
}

Plane* Driver::funcArgDec(char* arg_name, int arg_type, Plane* arg_follow) {
    Plane* id = setupPlane(N_IDEN);
    id->val.str = arg_name;

    Plane* type = setupPlane(N_DEC_DEC);
    type->val.i32 = arg_type;

    Plane* i = setupPlane(N_DEC_VAR);
    i->left = type;
    i->right = id;
    
    Plane* li = setupPlane(N_FUN_CAG);
    li->left = i;
    li->right = arg_follow;

    return li;
}

Plane* Driver::fromTo(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_WFT_NSP);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::fromToConstruct(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_WFT_SKP);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::funcCall(char* i, Plane* p1) {
    Plane* ident = setupPlane(N_IDEN);
    ident->val.str = i;
    
    Plane* func = setupPlane(N_FUN_CAL);
    func->left = ident;
    func->right = p1;
    return func;
}

Plane* Driver::funcArg(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_FUN_ARG);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::abtSeq(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_SEQ_CHN);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::abtSet(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_SET_CHN);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::bex(Plane* p1, Plane* p2, int opt) {
    Plane* i = setupPlane(opt);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::mathAdd(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_ADD);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::mathSub(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_SUB);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::mathDiv(Plane* p1, Plane* p2) { 
    Plane* i = setupPlane(N_DIV);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::mathMul(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_MUL);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::mathMod(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_MOD);
    i->left = p1;
    i->right = p2;
    return i;
}

Plane* Driver::mathPow(Plane* p1, Plane* p2) {
    Plane* i = setupPlane(N_POW);
    i->left = p1;
    i->right = p2;
    return i;
}
Plane* Driver::mathLen(Plane* p1) {
    Plane* i = setupPlane(N_LEN);
    i->left = p1;
    return i;
}

/*Plane* Driver::identifier(char* name) {
    Plane* i = setupPlane(N_IDEN);
    i->val.str
}*/

Plane* Driver::incDecOpt(Plane* obj, int opt) {
    Plane* i = setupPlane(opt);
    i->left = obj;
    return i;
}

Plane* Driver::index2(char* ident) {
    Plane* i = setupPlane(N_IDEN);
    i->val.str = ident;

    return this->index1(i);
}

Plane* Driver::index1(Plane* p) {
    Plane* p2 = setupPlane(N_INDX);
    p2->left = p;
    return p2;
}

Plane* Driver::i32(int val) {
    Plane* p = setupPlane(DT_I32);
    p->val.i32 = val;
    return p;
}

Plane* Driver::i64(long long val) {
    Plane* p = setupPlane(DT_I64);
    p->val.i64 = val;
    return p;
}

Plane* Driver::f32(float val) {
    Plane* p = setupPlane(DT_F32);
    p->val.f32 = val;
    return p;
}

Plane* Driver::f64(double val) {
    Plane* p = setupPlane(DT_F64);
    p->val.f64 = val;
    return p;
}

Plane* Driver::b(bool bo) {
    Plane* p = setupPlane(DT_BOOL);
    p->val.b = bo;
    return p;
}

Plane* Driver::str(char* c) {
    Plane* p = setupPlane(DT_STR);
    p->val.str = c;
    return p;
}

void Driver::finalizeTree() {
    printf("Hi there!");
}

void tabHelper(int l) {
    int i;
    for (i = 0; i < l; i++) {
        printf("  ");
    }
}

void noImplement(const char* s) {
    printf("%s not yet implemented.\n", s);
}

void traverseTreeSub(Plane* root, int level) {
    if (root == NULL)
        return;

    if (root->left != NULL) {
        traverseTreeSub(root->left, level + 1);
    }

    tabHelper(level);

    if (root->type == N_CONSTANT) {
        printf("'%f'", (float)root->val.i32);
    } else {
        printf("%d", root->type);
    }

    printf("\n");

    if (root->right != NULL) {
        traverseTreeSub(root->right, level + 1);
    }
}


void Driver::dumpStatement(Plane* r) {
    traverseTreeSub(r, 0);
    printf("\n\n");
}
















