#include "tree.h"
#include <stdio.h>

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


Node* addNode(Node* n1, Node* n2) {
    Node* n = createNode();
    n->left = n1;
    n->right = n2;
    n->type = N_ADD;
    return n;
}

Node* subNode(Node* n1, Node* n2) {
    Node* n = createNode();
    n->left = n1;
    n->right = n2;
    n->type = N_SUB;
    return n;
}

Node* multNode(Node* n1, Node* n2) {
    Node* n = createNode();
    n->left = n1;
    n->right = n2;
    n->type = N_MULT;
    return n;
}

Node* divNode(Node* n1, Node* n2) {
    Node* n = createNode();
    n->left = n1;
    n->right = n2;
    n->type = N_DIV;
    return n;
}

Node* modNode(Node* n1, Node* n2) {
    Node* n = createNode();
    n->left = n1;
    n->right = n2;
    n->type = N_MOD;
    return n;
}

Node* powNode(Node* n1, Node* n2) {
    Node* n = createNode();
    n->left = n1;
    n->right = n2;
    n->type = N_POW;
    return n;
}

Node* lenNode(Node* n1) {
    Node* n = createNode();
    n->center = n1;
    n->type = N_LEN;
    return n;
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
        traverseTree(root->left, level + 1);
    }

    tabHelper(level);

    if (root->type == N_CONSTANT) {
        printf("%f", root->value);
    } else if (root->type == N_LEN) {
        printf("|\n");
        if (root->center != NULL) {
            traverseTree(root->center, level + 1);
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
                printf("%");
                break;  
        }
    }

    printf("\n");

    if (root->right != NULL) {
        traverseTree(root->right, level + 1);
    }
}

void traverseTree(Node* root) {
    traverseTreeSub(root, 0);
}


















