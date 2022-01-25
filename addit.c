#include "addit.h"
#include "util.h"
#include "subt.h"


void testConvertNumber(int *number, int tester, char* s2, int *s2Position){

    char romanValue = getRomanValue(tester);
    while (*number >= tester){
        s2[(*s2Position)] = romanValue;
        (*s2Position)++;
        (*number) -= tester;
    }
}

void decilmalToAddRoman(char* s2, int decimals1){
    int s2Position = 0;
    int testers[] = {1000, 500, 100, 50, 10, 5, 1};
    for (int i = 0; i < N_ROMAN_CHARACTERS; i++) {
        testConvertNumber(&decimals1, testers[i], s2, &s2Position);
    }
}


bool additNotationMainTransform(char* s1, char** s2){
    char* auxS1 = (char*) calloc(strlen(s1), sizeof(int));
    *s2 = (char*) calloc(strlen(s1) + 50, sizeof(char)); //50 extras pq o tamanho da string pode mudar

    strcpy(auxS1, s1 );
    toUpperCase(auxS1);
    if (!isValidRoman(auxS1)){
        return false;
    }
    int decimals1 = romanToInt(auxS1);
    decilmalToAddRoman(*s2, decimals1);

    free(auxS1);

    return true;
}


bool intToRomanMain(int n, char** roman){
    if (n <= 0 || n >= 5000){
        return false;
    }
    char* additRoman = (char*) calloc(strlen(roman)+50, sizeof(char));
    decilmalToAddRoman(additRoman, n);
    subtNotationMainTransform(additRoman, roman);
    free(additRoman);
    return true;
}

bool transformRomanAndInt(char* op, char** dest){
    if (isValidRoman(op)){
        additNotationMainTransform(op, dest);
        return true;
    }else if (isValidInteger(op)){
        char* aux = (char*) calloc(strlen(op)+50, sizeof(char));
        intToRomanMain(atoi(op), &aux);
        additNotationMainTransform(aux, dest);
        free(aux);
        return true;
    }
    return false;
}


bool sumRomanNumbersMain(char* op1, char* op2, char** dest){
    char* upperop1 = (char*) calloc(strlen(op1) + 50, sizeof(char));
    char* upperop2 =(char*) calloc(strlen(op2) + 50, sizeof(char));
    char* additop1;
    char* additop2;

    strcpy(upperop1, op1);
    strcpy(upperop2, op2);
    toUpperCase(upperop1);
    toUpperCase(upperop2);

    bool exitc1 = transformRomanAndInt(upperop1, &additop1);
    bool exitc2 = transformRomanAndInt(upperop2, &additop2);
    if (!(exitc1 && exitc2)){
        return false;
    }
    strcat(additop1, additop2);
    subtNotationMainTransform(additop1, dest);

    free(upperop1);
    free(upperop2);
    free(additop1);
    free(additop2);
    return true;
}

