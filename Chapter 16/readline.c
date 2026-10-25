#include<stdio.h>
#include<ctype.h>
#include "readline.h"

void read_line(char* str, int n) {
	int i = 0, ch; 
	while(isspace(ch = getchar()));

	while(ch != '\n' && ch != EOF) {
		if(i < n) str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
}