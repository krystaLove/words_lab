#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Word.h"

int compareWord(Word a, Word b){
    return strncmp(a, b, WORD_MAX);
}
void toLowerCase(Word a){
    int i;
    int len = strnlen(a, WORD_MAX);
    for(i = 0; i<len; i++){
        if(a[i] >= (char)'A' && a[i] <='Z'){
            a[i] = (char)(a[i] + 'a' - 'A');
        }
    }
}