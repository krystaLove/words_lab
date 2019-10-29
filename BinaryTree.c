#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

void inOrderTraversal(BSTNode *x){
    if(x != NULL){
        inOrderTraversal(x->left);
        printf("HERE %s %d\n", x->data.word, x->data.rare);
        inOrderTraversal(x->right);
    }
}
BSTNode *insert(BSTNode *x, char* word){
    if(x == NULL){
        BSTNode *treeNode = (BSTNode*) malloc(sizeof(BSTNode));
        treeNode->data.word = malloc(sizeof(char) * (strlen(word) + 1));
        treeNode->data.rare = 1;
        strcpy(treeNode->data.word, word);
        treeNode->left = NULL;
        treeNode->right = NULL;
        return treeNode;
    } else if(compareWord(x->data.word, word) < 0){
        x->right = insert(x->right, word);
    } else if(compareWord(x->data.word, word) > 0){
        x->left = insert(x->left, word);
    }
    return x;
}
BSTNode *search(BSTNode *x, char* word){
    if(x == NULL || compareWord(x->data.word, word) == 0)
        return x;
    if(compareWord(word, x->data.word) < 0)
        return search(x->left, word);
    else
        return search(x->right, word);
}

static void inOrderTraversalAdd(BSTNode *x, Vector* vec) {
    if (x != NULL)
    {
        inOrderTraversalAdd(x->left, vec);
        addToVector(vec, x->data);
        inOrderTraversalAdd(x->right, vec);
    }
}

Vector* getArray(BSTNode *x, int amount){
    Vector *vec = (Vector*) malloc(sizeof(Vector));
    reserveVector(vec, amount);
    inOrderTraversalAdd(x, vec);

    return vec;
}

void FreeTree(BSTNode *x){
    if(x == NULL) return;
    FreeTree(x->right);
    FreeTree(x->left);
    free(x);
}