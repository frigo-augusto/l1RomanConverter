#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "addit.h"
#include "subt.h"



void main_alloc(char** a1, char** a2, char** d1, char** d2){
    *a1 = (char*) malloc(200*sizeof(char) + sizeof(char)); //somar 1 para dar espaco ao \0
    strcpy(*a1, "MMMMCMXCIX"); //inicializa a string
    *a2 = NULL; //alocacao eh feita dentro da funcao

    *d1 = (char*) malloc(100*sizeof(char) + sizeof(char));
    strcpy(*d1, "MMMMCMXCIX");
    *d2 = NULL;
}

void main_free(char** a1, char** a2, char** d1, char** d2){
    free(*a1);
    free(*a2);
    free(*d1);
    free(*d2);
}

int main() {
    char* s1 = (char*) malloc(200*sizeof(char) + sizeof(char)); //somar 1 para dar espaco ao \0
    char* s2 = NULL; //alocacao eh feita dentro da funcao
    strcpy(s1, "MMMCCCCLXXXX"); //inicializa a string
    //printf("%d", additNotationMainTransform(s1, &s2));
    printf("\n%d", subtNotationMainTransform(s1, &s2)); //nao funciona com "MMMCCCCCCLXXXX"
    printf("\ns1: %s    s2: %s", s1, s2);
    free(s1);
    free(s2);
    printf("\n");
    return 0;
}