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
bool isValid(char* s1);
void toUpperCase(char* s1);
void cleanStringZeros(char** c1);
bool romanGreaterThan(char r1, char r2);
int romanToInt(char* roman);
void orderRoman(char* s1, char* aux);
#endif
