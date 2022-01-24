#include "util.h"

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

bool isValidRoman(char* s1){
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

bool isValidInteger(char* number){
    for(int i = 0; i < strlen(number); i++){
        if (number[i] < '0' || number[i] > '9'){
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

void cleanStringZeros(char** c1){
    char* c2 = (char*) calloc(strlen(*c1) + 1, sizeof(char));
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

void orderRoman(char* s1, char* dest){
    int size = strlen(s1), destPosition = 0;
    char testers[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    for (int i = 0; i < N_ROMAN_CHARACTERS; i++){
        for(int j = 0; j < size; j++){
            if (s1[j] == testers[i]){
                dest[destPosition] = testers[i];
                destPosition++;
            }
        }
    }
}



