#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

#define INPUT "big.txt"
#define OUTPUT "output.txt"
#define TEXT_MAX 1000100

int main() {
    FILE *in = fopen(INPUT, "r");
    FILE *out = fopen(OUTPUT, "w");

    int wordsToPrint = -1;
    scanf("%d", &wordsToPrint);

    BSTNode *root = NULL;

    char current_word[WORD_MAX];
    char text[TEXT_MAX];
    int uniq_words_amount = 0;

    fscanf(in, "%[^" ALPHABET "]", text);
    fscanf(in, "%[" ALPHABET "]", current_word);
    fscanf(in, "%[^" ALPHABET "]", text);

    root = insert(root, current_word);
    if(root != NULL){
        uniq_words_amount++;
    }

    while(fscanf(in, "%[" ALPHABET "]", current_word) > 0){

        toLowerCase(current_word);

        BSTNode *find_node = search(root, current_word);
        if(find_node == NULL){
            insert(root, current_word);
            uniq_words_amount++;
        } else {
            find_node->data.rare++;
        }

        fscanf(in, "%[^" ALPHABET "]", text);
    }

    Vector *vec = getArray(root, uniq_words_amount);
    qsort(vec->data, uniq_words_amount, sizeof(Data), compareDataByRare);

    if(vec->size < wordsToPrint)
        wordsToPrint = vec->size;

    fprintf(out, "%d mostly used words:\n", wordsToPrint);

    int i;
    for(i = 0; i < wordsToPrint; i++){
        printData(vec->data[i], out);
    }

    printf("%d", uniq_words_amount);

    fclose(in);
    fclose(out);

    FreeTree(root);
    FreeVector(vec);

    return 0;
}