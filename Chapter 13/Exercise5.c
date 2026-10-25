#include<stdio.h>
#include<ctype.h>

#define MAX_LEN 100

void capitalize(char*);
int read_line(char*, int);

int main() {
	char msg[MAX_LEN+1];
	printf("Message : "); read_line(msg, MAX_LEN);
	capitalize(msg);
	printf("Capitalize : %s\n", msg);
}

void capitalize(char* str) {
	char* p = str;
	while(*p != '\0') *p++ = toupper(*p);
}

int read_line(char* str, int max) {
	int ch, i = 0;
	while((ch = getchar()) != '\n') {
		if(i < max) str[i++] = ch;
	} 
	str[i] = '\0';
	return i;
}