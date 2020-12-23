#include "strlib.h"
#include "cipher.h"

int main(int argc, char** argv) {
	char method[256];
	char text[256];	
	char key[256];
	
	if(argc == 1) {
		printf("-input method (-xor or -caesar)\n");
		scanf("%s",method);
		printf("text\n");
		scanf("%s",text);
		printf("key\n");
		scanf("%s",key);
	}
	else if(argc == 4) {
		strcpy(method,argv[1]);
		strcpy(text,argv[2]);
		strcpy(key,argv[3]);
	}
	else {
		printf("invalid number of arguments\n");
		return 1;
	}
	
	mutableToLower(method);
	
	if(strcmp(method, "-caesar") == 0) {
		if(!checkNumber(key)) {
			printf("offset error: not a number\n");
			return 2;
		}
		if(!checkWord(text)) {
			printf("text error: not a word\n");
			return 3;
		}
		mutableCaesar(text, -atoi(key));
	}
	else if(strcmp(method, "-xor") == 0) {
		mutableXOR(text, key);
	}
	else {
		printf("invalid method");
		return 4;
	}
	printf("decoded string %s\n", text);
	return 0;
}