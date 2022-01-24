#include "util.h"
#include "subt.h"

void transformAddictiveRoman(char* aux, char* transformedRomans){
    int size = strlen(aux), charTogether = 2, transformedRomansCounter = 0, j = 0;
    bool is5Loop = false;
    char testers[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    for (int i = 1; i < N_ROMAN_CHARACTERS; i++){
        int nCharTogether = 0;
        while(j < size){
            if (testers[i] == aux[j]){
                nCharTogether++;
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
        j = 0;
        is5Loop = !is5Loop;
        charTogether = 2 + (3*is5Loop);
    }
}

void transformDiminutiveRomans(char* aux, char* transformedRomans){
    int size = strlen(aux);
    char testers[] = {'C', 'X', 'I'};
    char auxConcat[] = {'D', 'L', 'V'};
    int j = 0;
    int transformedRomansCounter = 0;
    for (int i = 0; i < 3; i++){
        int nCharTogether = 0;
        while (j < size){
            printf("\ntesters[i]: %c aux[j]: %c", testers[i], aux[j]);
            if (testers[i] == aux[j]){
                nCharTogether++;
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
        j = 0;
        printf("   transfdimaux: %s    transfdimRom: %s", aux, transformedRomans);
    }
}


void concatFinalSubt(char** s2, char* s1Source, char* transformedAddictiveRomans, char* transformedDiminutiveRomans){
    *s2 = (char*) calloc((strlen(s1Source) + strlen(transformedDiminutiveRomans) + strlen(transformedDiminutiveRomans)), sizeof(char));
    char* aux = (char*) calloc((sizeof(s1Source) + sizeof(transformedAddictiveRomans)) + 1, sizeof(char));
    strcat(aux, transformedAddictiveRomans);
    strcat(aux, s1Source);
    orderRoman(aux, *s2);
    strcat(*s2, transformedDiminutiveRomans); // a logica de tudo parece certa, mas nao posso so concatenar no final
    free(aux);
}

bool subtNotationMainTransform(char* s1, char** s2){
    toUpperCase(s1);
    if (!isValidRoman(s1)){
        return false;
    }

    int size = strlen(s1);
    char* s1Source = (char*) calloc(size, sizeof(char));
    char* transformedAddictiveRomans = (char*) calloc(size+sizeof(char), sizeof(char));
    char* transformedDiminutiveRomans = (char*) calloc(size+50, sizeof(char)); //verificar o tamanho disso, pq pode expandir
    orderRoman(s1, s1Source);
    transformAddictiveRoman(s1Source, transformedAddictiveRomans);
    cleanStringZeros(&s1Source);
    transformDiminutiveRomans(s1Source, transformedDiminutiveRomans);
    cleanStringZeros(&s1Source);
    concatFinalSubt(s2, s1Source, transformedAddictiveRomans, transformedDiminutiveRomans);
    free(s1Source);
    free(transformedDiminutiveRomans);
    free(transformedAddictiveRomans);
    return true;
}
