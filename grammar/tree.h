#ifndef __TREE_HEADER
#define __TREE_HEADER

#define N_CONSTANT  0
#define N_MULT      1
#define N_DIV       2
#define N_ADD       3
#define N_SUB       4
#define N_MOD       5
#define N_POW       6
#define N_LEN       7

typedef struct Node {
    struct Node* left;
    struct Node* right;
    struct Node* center;
    int type;
    double value;
} Node;

Node* createNode();
Node* singleValue(double value);
Node* addNode(Node* n1, Node* n2);
Node* subNode(Node* n1, Node* n2);
Node* multNode(Node* n1, Node* n2);
Node* divNode(Node* n1, Node* n2);
Node* modNode(Node* n1, Node* n2);
Node* powNode(Node* n1, Node* n2);
Node* lenNode(Node* n1);

void traverseTree(Node* root);

#endif
