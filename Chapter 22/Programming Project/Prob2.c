#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void) {
	//Suppose that we have input and output files opened at stdin and stdout
	int ch; 
	while((ch = getchar()) != EOF) printf("%c", toupper(ch));
}