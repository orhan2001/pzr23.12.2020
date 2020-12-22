#include "cipher.h"


void mutableXOR(char* str, const char* key) {
	const int lengthSt = strlen(str); 
	const int lengthKey = strlen(key);
	
	for(int i = 0; i < lengthSt; i++) {
		str[i] ^= key[i % lengthKey];
	}
}

char* immutableXOR(const char* str, const char* key) {
	int length = strlen(str) + 1; 
	char* newStr = (char*) malloc(sizeof(char) * (length));
	strcpy(newStr,str);
	mutableXOR(newStr,key);

	return newStr;
}


void mutableCaesar(char* str, const int key) {
	const int length = strlen(str); 
	const int newKey = key % 26;
	
	for(int i = 0; i < length; i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {	
			if(str[i] + newKey > 'z') {
				str[i] -= ('z' - 'a') + 1;
			}
			if(str[i] + newKey < 'a') {
				str[i] += ('z' - 'a') + 1 ;
			}
			str[i] += newKey;
		}
  		if(str[i] >= 'A' && str[i] <= 'Z') {	
			if(str[i] + newKey > 'Z') {
				str[i] -= ('Z' - 'A') + 1;
			}
			if(str[i] + newKey < 'A') {
				str[i] += ('Z' - 'A') + 1;
			}
			str[i] += newKey;
		}
	}
}

char* immutableCaesar(const char* str, const int  key) {
	int length = strlen(str) + 1; 
	char* newStr = (char*) malloc(sizeof(char) * (length));
	strcpy(newStr,str);
	mutableCaesar(newStr,key);

	return newStr;
}