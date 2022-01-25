#include "util.h"

int getIntegerValue(char roman){
    switch (roman) {
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
        default:
            return 0;
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
        default:
            return 0;
            break;
    }
}

bool isValidRoman(char* roman){
    char validCharacters[] = "IVXLCDM";
    for(int i = 0; i < strlen(roman); i++){
        bool validChar = false;
        for(int j = 0; j < strlen(validCharacters); j++){
            if (roman[i] == validCharacters[j]){
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

bool isValidInteger(char* number){
    for(int i = 0; i < strlen(number); i++){
        if (number[i] < '0' || number[i] > '9'){
            return false;
        }
    }
    return true;
}


void toUpperCase(char* c){
    for(int i = 0; i < strlen(c); i++){
        if (c[i] >= 'a' && c[i] <= 'z'){
            *(c + i) = *(c + i) - 32;
        }
    }
}

void cleanStringZeros(char** c){
    char* c2 = (char*) calloc(strlen(*c) + 1, sizeof(char));
    int c2Counter = 0;
    for(int i = 0; i < strlen(*c); i++){
        if((*c)[i] != '0'){
            c2[c2Counter] = (*c)[i];
            c2Counter++;
        }
    }
    free(*c);
    *c = c2;
}


bool romanGreaterOrEqualThan(char r1, char r2){
    return getIntegerValue(r1) >= getIntegerValue(r2);
}

int romanToInt(char* roman){
    int accumulator = 0, size = strlen(roman);
    for(int i = 0; i < size; i++){
        bool isLower = false;
        for(int j = i + 1; j < size; j++){
            if (!romanGreaterOrEqualThan(roman[i], roman[j])){
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

void orderRoman(char* src, char* dest){
    int size = strlen(src), destPosition = 0;
    char testers[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    for (int i = 0; i < N_ROMAN_CHARACTERS; i++){
        for(int j = 0; j < size; j++){
            if (src[j] == testers[i]){
                dest[destPosition] = testers[i];
                destPosition++;
            }
        }
    }
}

void orderRomanWithSubt(char* srcAdd, char* srcSubt, char* dest){
    int s1size = strlen(srcAdd), s2size = strlen(srcSubt), destPosition = 0;
    char testers[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    for (int i = 0; i < N_ROMAN_CHARACTERS; i++){
        for(int j = 0; j < s1size; j++){
            if (srcAdd[j] == testers[i]){
                dest[destPosition] = testers[i];
                destPosition++;
            }
        }
        for(int j = 1; j < s2size; j+=2){
            if (srcSubt[j] == testers[i]){
                dest[destPosition] = srcSubt[j - 1];
                dest[destPosition + 1] = srcSubt[j];
                destPosition += 2;
            }
        }
    }
    dest[destPosition] = '\0';
}



