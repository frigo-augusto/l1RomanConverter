#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "addit.h"
#include "subt.h"


void testAddFunction(){
    char* s1 = (char*) calloc(200 + 1, sizeof(char)); //somar 1 para dar espaco ao \0
    char* s2 = NULL;
    strcpy(s1, "XXVIIIIXXIICCCCIIIXX");
    bool success = additNotationMainTransform(s1, &s2);
    if (success){
        printf("\n Teste da funcao de adicao \n Valor de s2: %s\n", s2);
        free(s2);
    }
    free(s1);
}

void testSubtFunction(){
    char* s1 = (char*) calloc(200 + 1, sizeof(char));
    char* s2 = NULL;
    strcpy(s1, "MMMCCCCCCLXXXX");
    bool success = subtNotationMainTransform(s1, &s2);
    if (success){
        printf("\n Teste da funcao de subtracao \n Valor de s2: %s\n", s2);
        free(s2);
    }
    free(s1);
}

void testPart2(){
    char* s2 = NULL;
    bool success = intToRomanMain(493, &s2);
    if (success){
        printf("\n Teste parte 2\n Valor de s2: %s\n", s2);
        free(s2);
    }
}

void testPart3(){
    char* op1 = (char*) calloc(200 + 1, sizeof(char));
    char* op2 = (char*) calloc(200 + 1, sizeof(char));
    char* dest;

    strcpy(op1, "29");
    strcpy(op2, "XXIII");
    bool success = sumRomanNumbersMain(op1, op2, &dest);
    if (success){
        printf("\n Teste parte 3 \n Valor da soma: %s\n", dest);
        free(dest);
    }
    free(op1);
    free(op2);
}




int main() {
    testAddFunction();
    testSubtFunction();
    testPart2();
    testPart3();
    return 0;
}