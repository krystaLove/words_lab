#include <stdio.h>
#include "Word.h"

typedef struct Data{
    Word word;
    int rare;
} Data;

void printData(Data data, FILE*);
int compareDataByRare(const void *a, const void *b);