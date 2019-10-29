#include "Vector.h"

typedef struct BSTNode{
    struct BSTNode *left, *right;
    Data data;
} BSTNode;

void inOrderTraversal(BSTNode *x);
BSTNode *insert(BSTNode *x, char* word);
BSTNode *search(BSTNode *x, char* word);
Vector* getArray(BSTNode *x, int amount);
void FreeTree(BSTNode *x);