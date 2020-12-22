#include "strlib.h"


void mutableToUpper(char* str) {
	const int length = strlen(str);
	for(int i = 0; i < length; i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 'a' - 'A';
		}
	}
}

char* immutableToUpper(const char* str) {
	int length = strlen(str) + 1; 
	char* newStr = (char*) malloc(sizeof(char) * (length));
	strcpy(newStr,str);
	mutableToUpper(newStr);

	return newStr;
}

 
void mutableToLower(char* str) {
	const int length = strlen(str);
	for(int i = 0; i < length; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
	}
}

char* immutableToLower(const char *str) {
	int length = strlen(str) + 1; 
	char* newStr = (char*) malloc(sizeof(char) * (length));
	strcpy(newStr,str);
	mutableToLower(newStr);

	return newStr;
}


void mutableStrip(char* str) {
	int length;
	int start = 0;  
	int finish = 0;
	if (strlen(str) == 0) {
		length = 0;
	} 
	else {
		finish = strlen(str) - 1;	
		while(str[start] == ' ') {
			if(str[start + 1] == '\0') {
				break;
			}
			start++;
		}	
		if (start == finish) {
			length = 0;
		}
		else {
			while (str[finish] == ' ') {
				finish--;
			}
			length = finish - start + 1;
			for(int i = 0; i < length; i++) {
				str[i] = str[start + i];
			}
		}
	}
	str[length] = '\0';
	
}

char* immutableStrip(const char* str) {
	int length = strlen(str) + 1; 
	
	char* newStr = (char*) malloc(sizeof(char) * (length));
	strcpy(newStr,str);
	mutableStrip(newStr);
	return newStr;
}	


void mutableSpaces(char* str) {
	int length = strlen(str);
	int i = 0, j = 0;
    
	while(str[i] != '\0') {
		if(str[i] == ' ') {
			for(j = i; j < length - 1; j++) {
				str[j] = str[j+1];
			}
			str[length-1] = '\0';
		    length--;
			continue;
		}
		i++;
	}
}

char* immutableSpaces(const char* str) {
	int length = strlen(str) + 1; 
	
	char* newStr = (char*) malloc(sizeof(char) * (length));
	strcpy(newStr,str);
	mutableSpaces(newStr);

	return newStr;
}


void mutableFilter(char* str) {
	int length = strlen(str);
	int i = 0, j = 0;
    
	while(str[i] != '\0') {
		if(!isalpha(str[i]) && !isspace(str[i]) && !isdigit(str[i])) {
			for(j = i; j < length - 1; j++){
				str[j] = str[j+1];
			}
			str[length-1] = '\0';
		    length--;
			continue;
		}
		i++;
	}
}

char* immutableFilter(const char* str) {
	int length = strlen(str) + 1; 
	char* newStr = (char*) malloc(sizeof(char) * (length));
	strcpy(newStr,str);
	mutableFilter(newStr);

	return newStr;
}


bool checkNumber(const char* str) {
	const int length = strlen(str);
	for(int i = 0; i < length; i++) {
		if(!isdigit(str[i])) {	
			return false;
		}
	}
	return true;
}

bool checkWord(const char* str) {
	const int length = strlen(str);
	for(int i = 0; i < length; i++) {
		if(!isalpha(str[i])) {	
			return false;
		}
	}
	return true;
}