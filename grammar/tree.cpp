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

void Driver::createDecl(int type, char* ident) {
    //printf("Declaring %s of type %d.\n", ident, type);
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
void Driver::mathLen() {
    //printf("len\n");
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

/*void traverseTreeSub(Node* root, int level) {
    if (root == NULL)
        return;

    if (root->left != NULL) {
        traverseTreeSub(root->left, level + 1);
    }

    tabHelper(level);

    if (root->type == N_CONSTANT) {
        printf("%f", root->value);
    } else if (root->type == N_LEN) {
        printf("|\n");
        if (root->center != NULL) {
            traverseTreeSub(root->center, level + 1);
        }
        tabHelper(level);
        printf("|\n");
    } else {
        switch (root->type) {
            case N_MULT:
                printf("*");
                break;
            case N_DIV:
                printf("/");
                break;
            case N_ADD:
                printf("+");
                break;
            case N_SUB:
                printf("-");
                break;
            case N_MOD:
                printf("%%");
                break;  
        }
    }

    printf("\n");

    if (root->right != NULL) {
        traverseTreeSub(root->right, level + 1);
    }
}

void traverseTree(Node* root) {
    traverseTreeSub(root, 0);
}*/


















