#include "Data.h"
#include <stdlib.h>
#include <stdio.h>
void printData(Data data){
    printf("%s - rare: %d\n", data.word, data.rare);
}
int compareDataByRare(const void *a, const void *b){
    return ((Data*)b)->rare - ((Data*)a)->rare;
}