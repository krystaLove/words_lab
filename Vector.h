#include "Data.h"

typedef struct Vector{
    Data *data;
    int size;
} Vector;

void addToVector(Vector* vec, Data data);
void reserveVector(Vector *vec, int reserved);
void FreeVector(Vector *vec);