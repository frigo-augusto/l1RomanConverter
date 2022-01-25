#include "util.h"
#include "subt.h"

void transformAddictiveRoman(char** addictiveAccumulator);

void checkNewTransforms(char** addictiveAccumulator, char* transformedRomans, bool hasTransformations){
    cleanStringZeros(addictiveAccumulator);
    strcat(*addictiveAccumulator, transformedRomans);
    char* aux = calloc(strlen(*addictiveAccumulator), sizeof(char));
    orderRoman(*addictiveAccumulator, aux);
    free(*addictiveAccumulator);
    free(transformedRomans);
    *addictiveAccumulator = aux;

    if (hasTransformations){
        transformAddictiveRoman(addictiveAccumulator);
    }
}

void transformAddictiveRoman(char** addictiveAccumulator){
    int size = strlen(*addictiveAccumulator), necessaryCharTogether = 2, transformedRomansCounter = 0, j = 0;
    char* transformedRomans = (char*) calloc(size, sizeof(char));
    bool is5Loop = false, hasTransformations = false;
    char testers[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    for (int i = 1; i < N_ROMAN_CHARACTERS; i++){
        int numberCharTogether = 0;
        while(j < size){
            if (testers[i] == (*addictiveAccumulator)[j]){
                numberCharTogether++;
            }
            if (numberCharTogether == necessaryCharTogether){
                transformedRomans[transformedRomansCounter] = testers[i - 1];
                transformedRomansCounter++;
                for (int k = 0; k < numberCharTogether; k++){
                    (*addictiveAccumulator)[j - k] = '0'; //removido
                }
                numberCharTogether = 0;
                hasTransformations = true;
            }
            j++;
        }
        j = 0;
        is5Loop = !is5Loop;
        necessaryCharTogether = 2 + (3 * is5Loop);
    }
    checkNewTransforms(addictiveAccumulator, transformedRomans, hasTransformations);
}

void transformDiminutiveRomans(char* src, char* dest){
    int size = strlen(src);
    char testers[] = {'C', 'X', 'I'};
    char auxConcat[] = {'D', 'L', 'V'};
    int j = 0;
    int destCounter = 0;
    for (int i = 0; i < 3; i++){
        int nCharTogether = 0;
        while (j < size){
            if (testers[i] == src[j]){
                nCharTogether++;
            }
            if (nCharTogether == 4){
                dest[destCounter] = testers[i];
                dest[destCounter + 1] = auxConcat[i];
                destCounter+=2;
                for (int k = 0; k < nCharTogether; k++){
                    src[j - k] = '0'; //removido
                }
                nCharTogether = 0;
            }
            j++;
        }
        j = 0;
    }
}



void concatFinalSubt(char** s2, char* s1Source, char* transformedDiminutiveRomans){
    *s2 = (char*) calloc((strlen(s1Source) + strlen(transformedDiminutiveRomans) + strlen(transformedDiminutiveRomans)), sizeof(char));
    char* aux = (char*) calloc((sizeof(s1Source) + sizeof(s1Source)) + 1, sizeof(char));
    strcat(aux, s1Source);
    orderRomanWithSubt(aux, transformedDiminutiveRomans, *s2);
    free(aux);
}

bool subtNotationMainTransform(char* s1, char** s2){
    toUpperCase(s1);
    if (!isValidRoman(s1)){
        return false;
    }

    int size = strlen(s1);
    char* addictiveAccumulator = (char*) calloc(size + 50, sizeof(char));
    char* diminutiveRomans = (char*) calloc(size + 50, sizeof(char)); //50 extras pq pode expandir
    orderRoman(s1, addictiveAccumulator);

    transformAddictiveRoman(&addictiveAccumulator);
    transformDiminutiveRomans(addictiveAccumulator, diminutiveRomans);
    cleanStringZeros(&addictiveAccumulator);
    concatFinalSubt(s2, addictiveAccumulator, diminutiveRomans);
    free(addictiveAccumulator);
    free(diminutiveRomans);
    return true;
}
