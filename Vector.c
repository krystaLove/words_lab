#include <stdlib.h>
#include "Vector.h"

void addToVector(Vector* vec, Data data){
    vec->data[vec->size++] = data;
}
void reserveVector(Vector *vec, int reserved){
    vec->data = (Data*) calloc(reserved, sizeof(Data));
    vec->size = 0;
}
void FreeVector(Vector *vec){
    free(vec->data);
    free(vec);
}