#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

#define TEXT_MAX 1000100

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    int howMany = -1;
    scanf("%d\n", &howMany);

    BSTNode *root = NULL;

    char current_word[WORD_MAX];
    char text[TEXT_MAX];
    int uniq_words_amount = 0;

    while(fscanf(in, "%[" ALPHABET "]", current_word) > 0){

        Word word;
        strncpy(word, current_word, WORD_MAX);
        toLowerCase(&word);

        if(root == NULL){
            root = insert(root, word);
            uniq_words_amount++;
            fscanf(in, "%[^" ALPHABET "]", text);
            continue;
        }

        BSTNode *find_node = search(root, word);
        if(find_node == NULL){
            insert(root, word);
            uniq_words_amount++;
        } else {
            find_node->data.rare++;
        }

        fscanf(in, "%[^" ALPHABET "]", text);
    }

    Vector *vec = getArray(root, uniq_words_amount);
    qsort(vec->data, uniq_words_amount, sizeof(Data), &compareDataByRare);

    if(vec->size < howMany)
        howMany = vec->size;

    fprintf(out, "%d mostly used words:\n", howMany);

    int i;
    for(i = 0; i < howMany; i++){
        printData(vec->data[i], out);
    }

    printf("%d", uniq_words_amount);

    fclose(in);
    fclose(out);

    FreeTree(root);
    FreeVector(vec);

    return 0;
}