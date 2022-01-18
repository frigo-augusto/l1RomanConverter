#include "addit.h"
#include "util.h"


void testConvertNumber(int *number, int tester, char* s2, int *s2Position){

    char romanValue = getRomanValue(tester);
    while (*number >= tester){
        s2[(*s2Position)] = romanValue;
        (*s2Position)++;
        (*number) -= tester;
    }
}

void decilmalToAddRoman(char* s1, char* s2, int decimals1){
    int s2Position = 0;
    int testers[] = {1000, 500, 100, 50, 10, 5, 1};
    for (int i = 0; i < N_ROMAN_CHARACTERS; i++) {
        testConvertNumber(&decimals1, testers[i], s2, &s2Position);
    }
}

bool additNotationMainTransform(char* s1, char** s2){
    char* auxS1 = (char*) malloc(strlen(s1) * sizeof(int));
    *s2 = (char*) malloc((strlen(s1) + 50)*sizeof(char)); //50 extras pq o tamanho da string pode mudar
    strcpy(auxS1, s1 );
    toUpperCase(auxS1);
    if (!isValid(auxS1)){
        return false;
    }
    int decimals1 = romanToInt(auxS1);
    decilmalToAddRoman(auxS1, *s2, decimals1);
    free(auxS1);
    return true;
}
