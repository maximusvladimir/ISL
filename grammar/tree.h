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
#define N_IDEN      8

#define A_REG       0
#define A_ADD       1
#define A_SUB       2
#define A_MUL       3
#define A_DIV       4
#define A_MOD       5
#define A_DEP       6

#define DT_NONE     0
#define DT_VAR      1
#define DT_LIST     2
#define DT_SET      3
#define DT_I8       4
#define DT_I16      5
#define DT_I32      6
#define DT_I64      7
#define DT_UI8      8
#define DT_UI16     9
#define DT_UI32     10
#define DT_UI64     11
#define DT_F32      12
#define DT_F64      13

typedef struct Node {
    struct Node* left;
    struct Node* right;
    struct Node* center;
    int type;
    double value;
    char* identifier;
} Node;

typedef struct Assignment {
    char* varName;
    Node* right;
    int type;    // the type of the operator. Example:    ...  *=  ...,   ...  ~= ...
    int deftype; // the type of define.       Example: var ... :=  ..., i8 ... := ...
} Assignment;

typedef struct FunctionCallParam {
    Node* value;
    struct FunctionCallParam next;
} FunctionCallParam;

typedef struct FunctionCall {
    char* functionName;
    FunctionCallParam params;
} FunctionCall;

typedef struct FromTo {
    Node* start;
    Node* end;
} FromTo;

typedef struct ForLoop {
    char* identifier;
    FromTo range;
    RootBlockList contents;
} ForLoop;

typedef struct IfBlock {
} IfBlock;

typedef struct FunctionParam {
    int type;   // the type of variable (see DT_...).
    char* name; // the identifier of the function variable.
    struct FunctionParam next;
} FunctionParam;

typedef struct FuncDecl {
    int type; // the type of return (see DT_...).
    char* name;
    FunctionParam params;
} FuncDecl;

typedef struct Block {
    ForLoop loop;
    IfBlock ifblock;
    FuncDecl func;
} Block;

typedef struct Statement {
    FunctionCall call;
    Assignment assignment;
} Statement;

typedef struct RootBlockList {
    struct RootBlockList next;
    Statement line;
} StatementBlock;

Node* createNode();
Node* singleValue(double value);
Node* addNode(Node* n1, Node* n2);
Node* subNode(Node* n1, Node* n2);
Node* multNode(Node* n1, Node* n2);
Node* divNode(Node* n1, Node* n2);
Node* modNode(Node* n1, Node* n2);
Node* powNode(Node* n1, Node* n2);
Node* lenNode(Node* n1);

Assignment* createAssignment(char* varName, Node* right, int type, int deftype);

void traverseTree(Node* root);

#endif
