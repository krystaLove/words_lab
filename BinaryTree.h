#include "vector.h"

typedef struct TreeNode{
    struct TreeNode *left, *right;
    Data data;
} TreeNode;

void inOrderTraversal(TreeNode *x);
TreeNode *insert(TreeNode *x, Word word);
TreeNode *search(TreeNode *x, Word word);
Vector* getArray(TreeNode *x, int amount);