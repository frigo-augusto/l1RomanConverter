//
// Created by jonas on 18/01/2022.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UTIL_H
#define N_ROMAN_CHARACTERS 7
#define UTIL_H
int getIntegerValue(char c);
char getRomanValue(int n);
bool isValidRoman(char* roman);
void toUpperCase(char* c);
void cleanStringZeros(char** c);
bool isValidInteger(char* number);
int romanToInt(char* roman);
void orderRoman(char* src, char* aux);
void orderRomanWithSubt(char* srcAdd, char* srcSubt, char* dest);
#endif
