#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Word.h"
#include "BinaryTree.h"
//#include "vector.h"
#define alphabet "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define TEXTMAX 1000100

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    TreeNode *root = NULL;

    char current_word[WORDMAX];
    char text[TEXTMAX];
    int words = 0;

    while(fscanf(in, "%[" alphabet "]", current_word) > 0){
        //fputs(current_word, out);

        Word word;
        strncpy(word, current_word, WORDMAX);

        if(root == NULL){
            root = insert(root, word);
            words++;
            fscanf(in, "%[^" alphabet "]", text);
            continue;
        }

        TreeNode *find_node = search(root, word);
        if(find_node == NULL){
            insert(root, word);
            words++;
        } else {
            find_node->data.rare++;
        }

        fscanf(in, "%[^" alphabet "]", text);
    }
    //inOrderTraversal(root);
    Vector *vec = getArray(root, words);
    qsort(vec->data, words, sizeof(Data), &compareDataByRare);
    int i;
    for(i = 0; i<vec->size; i++){
        printData(vec->data[i]);
    }

    //printf("%s\n", root->data.word.word);
    printf("%d", words);
    fclose(in);
    fclose(out);

    return 0;
}