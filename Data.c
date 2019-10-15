#include <stdio.h>
#include "Data.h"

void printData(Data data, FILE *out){
    fprintf(out,"%s [%d rareness]\n", data.word, data.rare);
}
int compareDataByRare(const void *a, const void *b){
    return ((Data*)b)->rare - ((Data*)a)->rare;
}