#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "addit.h"
#include "subt.h"
#include "util.h"


void testAddFunction(){
    char* s1 = (char*) calloc(200 + 1, sizeof(char)); //somar 1 para dar espaco ao \0
    char* s2 = NULL; //alocacao eh feita dentro da funcao
    strcpy(s1, "XXVIIIIXXIICCCCIIIXX"); //inicializa a string
    printf("%d", additNotationMainTransform(s1, &s2));
    free(s1);
    free(s2);
}

void testSubtFunction(){
    char* s1 = (char*) calloc(200 + 1, sizeof(char)); //somar 1 para dar espaco ao \0
    char* s2 = NULL;
    strcpy(s1, "MMMCCCCCCLXXXX");
    printf("\n%d", subtNotationMainTransform(s1, &s2));
    free(s1);
    free(s2);
}

void testPart2(){
    char* s2 = NULL;
    intToRomanMain(493, &s2);
    free(s2);
}

void testPart3(){
    char* p1 = (char*) calloc(200 + 1, sizeof(char));
    char* p2 = (char*) calloc(200 + 1, sizeof(char));
    char* dest;
    strcpy(p1, "29");
    strcpy(p2, "XXIII");
    sumRomanNumbersMain(p1, p2, &dest);
    printf("\ndestino: %s\n", dest);
    int value = romanToInt(dest);
    printf(" valor: %d\n", value);
    free(p1);
    free(p2);
    free(dest);
}




int main() {
    testAddFunction();
    testSubtFunction();
    testPart2();
    testPart3();
    return 0;
}