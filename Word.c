#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Word.h"

int compareWord(Word a, Word b){
    return strncmp(a, b, WORDMAX);
}