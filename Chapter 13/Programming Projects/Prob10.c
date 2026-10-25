#include<stdio.h>
#include<ctype.h>
#define MAX_LENGTH 100

void read_line(char*, int);

int main(void) {
	char name[2][MAX_LENGTH + 1];

	printf("Enter a first and last name : ");
	read_line(name[0], MAX_LENGTH);
	read_line(name[1], MAX_LENGTH);
	printf("%s, %c.\n", name[1], name[0][0]);
}

void read_line(char* str, int max) {
	int ch, i = 0; 
	while( !isspace(ch = getchar()) && i < max) str[i++] = ch;
	str[i] = '\0'; 
}