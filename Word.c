#include <string.h>
#include "Word.h"

int compareWord(char* a, char* b){
    return strncmp(a, b, WORD_MAX);
}
void toLowerCase(char* a){
    int i;
    int len = strnlen(a, WORD_MAX);
    for(i = 0; i<len; i++){
        if(a[i] >= (char)'A' && a[i] <='Z'){
            a[i] = (char)(a[i] + 'a' - 'A');
        }
    }
}