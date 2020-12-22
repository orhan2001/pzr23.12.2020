#ifndef H_STRLIB
#define H_STRLIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void  mutableToUpper(char* str);
char* immutableToUpper(const char* str);

void  mutableToLower(char* str);
char* immutableToLower(const char* str);

void  mutableStrip(char* str);
char* immutableStrip(const char* str);

void  mutableSpaces(char* str);
char* immutableSpaces(const char* str);

void  mutableFilter(char* str);
char* immutableFilter(const char* str);

bool checkNumber(const char* str);
bool checkWord(const char* str);

#endif