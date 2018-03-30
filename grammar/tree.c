#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

Node* createNode() {
    Node* n = (Node*)malloc(sizeof(Node*));
    n->left = n->right = n->center = NULL;
    n->type = -1;
    n->value = 0;
    return n;
}

Node* singleValue(double value) {
    Node* n = createNode();
    n->type = N_CONSTANT;
    n->value = value;
    return n;
}

Node* binary(Node* n1, Node* n2, int type) {
    Node* n = createNode();
    n->left = n1;
    n->right = n2;
    n->type = type;
}

Node* addNode(Node* n1, Node* n2) {
    return binary(n1, n2, N_ADD);
}

Node* subNode(Node* n1, Node* n2) {
    return binary(n1, n2, N_SUB);
}

Node* multNode(Node* n1, Node* n2) {
    return binary(n1, n2, N_MULT);
}

Node* divNode(Node* n1, Node* n2) {
    return binary(n1, n2, N_DIV);
}

Node* modNode(Node* n1, Node* n2) {
    return binary(n1, n2, N_MOD);
}

Node* powNode(Node* n1, Node* n2) {
    return binary(n1, n2, N_POW);
}

Node* lenNode(Node* n1) {
    Node* n = createNode();
    n->center = n1;
    n->type = N_LEN;
    return n;
}


Assignment* createAssignment(char* varName, Node* right, int type, int deftype) {
    Assignment* a = (Assignment*)malloc(sizeof(Assignment*));
    a->varName = varName;
    a->right = right;
    a->type = type;
    a->deftype;
    return a;
}

void tabHelper(int l) {
    int i;
    for (i = 0; i < l; i++) {
        printf("  ");
    }
}

void traverseTreeSub(Node* root, int level) {
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
}


















