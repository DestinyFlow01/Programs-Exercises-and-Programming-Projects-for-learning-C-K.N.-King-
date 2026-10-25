#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* duplicate(char* str) {
	char* new_str = malloc(strlen(str) + 1);
	if(new_str == NULL) return NULL;

	strcpy(new_str, str);
	return new_str;
}