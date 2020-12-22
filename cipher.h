#ifndef H_CIPHER
#define H_CIPHER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void  mutableXOR(char* str, const char* key);
char* immutableXOR(const char* str , const char* key);

void  mutableCaesar(char* str, const int key);
char* immutableCaesar(const char* str, const int key);

#endif