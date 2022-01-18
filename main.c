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
    char* a1, a2, d1, d2;
    main_alloc(a1, a2, d1, d2);

    printf("%d", additNotationMainTransform(a1, &a2));
    printf("\ns1: %s    s2: %s", a1, a2);



    main_free(a1, a2, d1, d2);
    return 0;
}