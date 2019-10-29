#include <stdio.h>
#include "Data.h"

void printData(Data data, FILE *out){
    fprintf(out,"%-10s %-10d\n", data.word, data.rare);
}
int compareDataByRare(const void *a, const void *b){
    return ((Data*)b)->rare - ((Data*)a)->rare;
}