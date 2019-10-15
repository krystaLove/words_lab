#include "vector.h"
#include <stdlib.h>

void addToVector(Vector* vec, Data data){
    vec->data[vec->size++] = data;
}
void reserveVector(Vector *vec, int reserved){
    vec->data = (Data*) malloc(sizeof(Data) * reserved);
    vec->size = 0;
}