#ifndef __TREE_HEADER
#define __TREE_HEADER

#define N_CONSTANT  0       // Numeric constant (not used).
#define N_MUL       1       // Math multiplication operator
#define N_DIV       2       // Math division operator
#define N_ADD       3       // Math add operator
#define N_SUB       4       // Math subtract operator
#define N_MOD       5       // Math MODULUS operator
#define N_POW       6       // Math pow operator
#define N_LEN       7       // Length operator
#define N_IDEN      8       // Identifier
#define N_INDX      9       // Array indexing operation
#define N_PST_INC   10      // Postfix increment operator
#define N_PST_DEC   11      // Postfix decrement operator
#define N_PRE_INC   12      // Prefix increment operator
#define N_PRE_DEC   13      // Prefix decrement operator
#define N_UNI_DEP   14      // Deep Unary Operator
#define N_UNI_NEG   15      // Negative Unary Operator
#define N_UNI_POS   16      // Positive Uniary Operator
#define N_UNI_LNG   17      // Logical NOT Uniary Operator
#define N_BEX_LES   18      // Boolean less than
#define N_BEX_GRT   19      // Boolean greater than
#define N_BEX_LEQ   20      // Boolean less or equal to
#define N_BEX_GEQ   21      // Boolean greater or equal to
#define N_BEX_NEQ   22      // Boolean !=
#define N_BEX_EQU   23      // Boolean =
#define N_BEX_AND   24      // Boolean &&
#define N_BEX_ORR   25      // Boolean ||
#define N_SEQ_CHN   26      // Sequence (list) chain (aka linked list)
#define N_SET_CHN   27      // Set chain (aka linked list)
#define N_FUN_CAL   28      // Function call (left: function identifier, right: argument list (or null)).
#define N_FUN_ARG   29      // Function call argument list (left: first parameter, right: next parameter (or null)).
#define N_WFT_SKP   30      // From-To skip construct.
#define N_WFT_NSP   31      // From-To without the skip construct.
#define N_DEC_VAR   32      // A variable declaration that may or may not have a type. (left: type, right: identifier).
#define N_FUN_CAG   33      // Function call argument list.
#define N_DEC_DEC   34      // Filler decl.
#define N_ARR_IDX   35      // Array indexing operation.
#define N_IDX_MAR   36      // Array indexing multiargument. The left is the first argument. The right may or may not be null.

#define A_REG       100
#define A_ADD       101
#define A_SUB       102
#define A_MUL       103
#define A_DIV       104
#define A_MOD       105
#define A_DEP       106
#define A_NON       107

#define DT_NONE     1000
#define DT_VAR      1001
#define DT_LIST     1002
#define DT_SET      1003
#define DT_I8       1004
#define DT_I16      1005
#define DT_I32      1006
#define DT_I64      1007
#define DT_UI8      1008
#define DT_UI16     1009
#define DT_UI32     1010
#define DT_UI64     1011
#define DT_F32      1012
#define DT_F64      1013
#define DT_STR      1014
#define DT_BOOL     1015

typedef union PType {
    char i8;
    unsigned char ui8;
    short i16;
    unsigned short ui16;
    int i32;
    unsigned int ui32;
    long long i64;
    unsigned long long ui64;
    float f32;
    double f64;
    char* str;
    bool b;
} PType;

typedef struct Plane {
    Plane* left;
    Plane* right;
    int type;
    PType val;
} Plane;

class Driver {
    public:
        Driver();
        Plane* createDecl(int type, char* ident, int a_type, Plane* right_side);
        Plane* mathAdd(Plane* p1, Plane* p2);
        Plane* mathSub(Plane* p1, Plane* p2);
        Plane* mathDiv(Plane* p1, Plane* p2);
        Plane* mathMul(Plane* p1, Plane* p2);
        Plane* mathMod(Plane* p1, Plane* p2);
        Plane* mathPow(Plane* p1, Plane* p2);
        Plane* mathLen(Plane* p1);
        Plane* i32(int val);
        Plane* i64(long long val);
        Plane* f32(float val);
        Plane* f64(double val);
        Plane* b(bool bo);
        Plane* str(char* s);
        Plane* index2(char* ident);
        Plane* incDecOpt(Plane* obj, int opt);
        Plane* bex(Plane* p1, Plane* p2, int opt);
        Plane* abtSeq(Plane* p1, Plane* p2);
        Plane* abtSet(Plane* p1, Plane* p2);
        Plane* funcCall(char* i, Plane* p1);
        Plane* funcArg(Plane* p1, Plane* p2);
        Plane* fromToConstruct(Plane* p1, Plane* p2);
        Plane* fromTo(Plane* p1, Plane* p2);
        Plane* funcArgDec(char* arg_name, int arg_type, Plane* arg_follow);
        Plane* indexing(char* var, Plane* index);
        Plane* indexOpt(Plane* from, Plane* to);
        void dumpStatement(Plane* p);
        void finalizeTree();
};

void noImplement(const char* s);

//void traverseTree(Plane* root);

#endif
