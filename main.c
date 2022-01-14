#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define N_ROMAN_CHARACTERS 7

int getIntegerValue(char c){
    switch (c) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
    }
}

char getRomanValue(int n){
    switch (n) {
        case 1:
            return 'I';
            break;
        case 5:
            return 'V';
            break;
        case 10:
            return 'X';
            break;
        case 50:
            return 'L';
            break;
        case 100:
            return 'C';
            break;
        case 500:
            return 'D';
            break;
        case 1000:
            return 'M';
            break;
    }
}

bool isValid(char* s1){
    char validCharacters[] = "IVXLCDM";
    for(int i = 0; i < strlen(s1); i++){
        bool validChar = false;
        for(int j = 0; j < strlen(validCharacters); j++){
            if (s1[i] == validCharacters[j]){
                validChar = true;
                break;
            }
        }
        if (validChar == false){
            return false;
        }
    }
    return true;
}

void toUpperCase(char* s1){
    for(int i = 0; i < strlen(s1); i++){
        if (s1[i] >= 97 && s1[i]<= 122){
            *(s1+i) = *(s1+i) - 32;
        }
    }
}

bool romanGreaterThan(char r1, char r2){
    return getIntegerValue(r1) > getIntegerValue(r2);
}

void testNumberConversion(int *number, int tester, char* s2, int *s2Position){

    char romanValue = getRomanValue(tester);
    while (*number >= tester){
        s2[(*s2Position)] = romanValue;
        (*s2Position)++;
        printf("%d    ", *s2Position);
        (*number) -= tester;
        printf("%d", *number);
    }
}

int romanToInt(char* roman){
    int accumulator = 0;
    int size = strlen(roman);
    for(int i = 0; i < size; i++){
        bool isLower = false;
        for(int j = i + 1; j < size; j++){
            if (!romanGreaterThan(roman[i], roman[j])){
                accumulator -= getIntegerValue(roman[i]);
                isLower = true;
                break;
            }
        }
        if (!isLower){
            accumulator += getIntegerValue(roman[i]);
        }
    }
    return accumulator;
}

void decilmalToAddRoman(char* s1, char* s2, int decimals1){
    int s2Position = 0;
    int testers[] = {1000, 500, 100, 50, 10, 5, 1};
    for (int i = 0; i < N_ROMAN_CHARACTERS; i++) {
        printf("tua vo");
        testNumberConversion(&decimals1, testers[i], s2, &s2Position);
    }
    printf("      %s        ", s2);
}

bool additNotationTransform(char* s1, char* s2){
    toUpperCase(s1);
    if (!isValid(s1)){
        return false;
    }
    int decimals1 = romanToInt(s1);
    printf("\nAcumulador: %d\n", decimals1);
    decilmalToAddRoman(s1, s2, decimals1);

    return true;
}

void orderRoman(char* s1, char* aux){
    int size = strlen(s1);
    int auxPosition = 0;
    char testers[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    for (int i = 0; i < N_ROMAN_CHARACTERS; i++){
        for(int j = 0; j < size; j++){
            if (s1[j] == testers[i]){
                aux[auxPosition] = testers[i];
                auxPosition++;
            }
        }
    }
}

void transformAddictiveRoman(char* aux, char* transformedRomans){
    int size = strlen(aux);
    bool is5Loop = false;
    int charTogether = 2;
    int auxCounter = 0;
    int transformedRomansCounter = 0;
    char testers[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int j = 0;
    for (int i = 1; i < N_ROMAN_CHARACTERS; i++){
        int nCharTogether = 0;
        while(j < size){
            if (testers[i] == aux[j]){
                nCharTogether++;
            }
            else{
                break; //caracteres estao ordenados, continuar o loop apos ser diferente e inutil
            }
            if (nCharTogether == charTogether){
                transformedRomans[transformedRomansCounter] = testers[i - 1];
                transformedRomansCounter++;
                for (int k = 0; k < nCharTogether; k++){
                    aux[j - k] = '0'; //removido
                }
                nCharTogether = 0;
            }
            j++;
        }
    is5Loop = !is5Loop;
    charTogether = 2 + (3*is5Loop);
    }
}

void transformDiminutiveRomans(char* aux, char* transformedRomans){
    int size = strlen(aux);
    bool is5Loop = false;
    char testers[] = {'C', 'X', 'I'};
    char auxConcat[] = {'D', 'L', 'V'};
    int j = 0;
    int transformedRomansCounter = 0;
    for (int i = 0; i < 3; i++){
        int nCharTogether = 0;
        while (j < size){
            printf("\ntesters[i]: %c aux[j]: %c", testers[i], aux[j]);
            if (testers[i] == aux[j]){
                printf("charTogether++");
                nCharTogether++;
            }
            else{
                for (int k = 0; k < 3; k++){
                    if (aux[j] == auxConcat[k]){
                        j++;
                        i--;
                        break;
                    }
                }
                break; //caracteres estao ordenados, continuar o loop apos ser diferente e inutil
            }
            if (nCharTogether == 4){
                transformedRomans[transformedRomansCounter] = testers[i];
                transformedRomans[transformedRomansCounter+1] = auxConcat[i];
                transformedRomansCounter+=2;
                for (int k = 0; k < nCharTogether; k++){
                    aux[j - k] = '0'; //removido
                }
                nCharTogether = 0;
            }
            j++;
        }
        printf("   transfdimaux: %s    transfdimRom: %s", aux, transformedRomans);
    }
}

void cleanStringZeros(char** c1){
    char* c2 = (char*) malloc(strlen(*c1)*sizeof(char) + sizeof(char));
    int c2Counter = 0;
    for(int i = 0; i < strlen(*c1); i++){
        if((*c1)[i] != '0'){
            c2[c2Counter] = (*c1)[i];
            c2Counter++;
        }
    }
    free(*c1);
    *c1 = c2;
}


bool subtNotationTransform(char* s1, char** s2){
    int size = strlen(s1);
    char* s1Source = (char*) malloc(size*sizeof(char) + sizeof(char));
    char* transformedAddictiveRomans = (char*) malloc(sizeof(char) + sizeof(char));
    char* transformedDiminutiveRomans = (char*) malloc(size*sizeof(char) + sizeof(char));
    orderRoman(s1, s1Source);
    transformAddictiveRoman(s1Source, transformedAddictiveRomans);
    cleanStringZeros(&s1Source);
    transformDiminutiveRomans(s1Source, transformedDiminutiveRomans);
    cleanStringZeros(&s1Source);
    //CONCATENACAO DE STRING POSSIVELMENTE DANDO SEGMENTATION FAULT
    *s2 = (char*) malloc(sizeof(char)* (strlen(s1Source) + strlen(transformedDiminutiveRomans) + strlen(transformedDiminutiveRomans)));
    strcat(*s2, s1Source);
    strcat(*s2, transformedAddictiveRomans);
    strcat(*s2, transformedDiminutiveRomans);
    free(s1Source);
    free(transformedDiminutiveRomans);
}



int main() {
    char* s1 = (char*) malloc(200*sizeof(char) + sizeof(char)); //somar 1 para dar espaco ao \0
    char* s2 = NULL; //alocacao eh feita dentro da funcao
    char* s3 = (char*) malloc(100*sizeof(char) + sizeof(char));
    strcpy(s1, "IIIIIIIIIIIIIIIIDLXXIII"); //inicializa a string
    //printf("%d", additNotationTransform(s1, s2));
    //subtNotationTransform(s1, s2);
    //printf("%s %s", s1, s2);
    //transformAddictiveRoman(s1, s2);
    //cleanStringZeros(&s1);
    subtNotationTransform(s1, &s2);
    printf("\ns1: %s    s2: %s", s1, s2);
    free(s1);
    free(s2);
    free(s3);
    printf("\n");
    return 0;
}