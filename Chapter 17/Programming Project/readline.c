#include<stdio.h>
#include<ctype.h>
#include "readline.h"

int read_line(char* msg, int n) {
	int i = 0, ch; 
	while(isspace(ch = getchar()));
	while(ch != EOF && ch != '\n') {
		if(i < n) msg[i++] = ch;
		ch = getchar(); 
	}
	msg[i] = '\0';
	return i;
}