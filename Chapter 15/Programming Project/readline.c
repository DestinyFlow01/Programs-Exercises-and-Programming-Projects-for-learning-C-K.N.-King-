#include<stdio.h>
#include<ctype.h>

int readline(char* reminder, int max_length) {
	int ch;
	int i = 0; 
	while((ch = getchar()) != '\n' && i < max_length) {
		reminder[i++] = ch;
	}
	reminder[i] = '\0';
	return i;
}