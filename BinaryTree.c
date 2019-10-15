#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

void inOrderTraversal(TreeNode *x){
    if(x != NULL){
        inOrderTraversal(x->left);
        printf("HERE %s %d\n", x->data.word, x->data.rare);
        inOrderTraversal(x->right);
    }
}
TreeNode *insert(TreeNode *x, Word word){
    if(x == NULL){
        TreeNode *treeNode = (TreeNode*) malloc(sizeof(TreeNode));
        strncpy(treeNode->data.word, word, WORDMAX);
        treeNode->left = NULL;
        treeNode->right = NULL;
        treeNode->data.rare = 1;
       // printf("%s\n", treeNode->data.word.word);
        return treeNode;
    } else if(compareWord(x->data.word, word) < 0){
        x->right = insert(x->right, word);
    } else if(compareWord(x->data.word, word) > 0){
        x->left = insert(x->left, word);
    }
    return x;
}
TreeNode *search(TreeNode *x, Word word){
    if(x == NULL || compareWord(x->data.word, word) == 0)
        return x;
    if(compareWord(word, x->data.word) < 0)
        return search(x->left, word);
    else
        return search(x->right, word);
}

static void inOrderTraversalAdd(TreeNode *x, Vector* vec) {
    if (x != NULL)
    {
        inOrderTraversalAdd(x->left, vec);
        addToVector(vec, x->data);
        inOrderTraversalAdd(x->right, vec);
    }
}

Vector* getArray(TreeNode *x, int amount){
    Vector *vec = (Vector*) malloc(sizeof(Vector));
    reserveVector(vec, amount);
    inOrderTraversalAdd(x, vec);

    return vec;
}