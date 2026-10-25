#include<stdio.h>
#include<string.h>

#define MAX_LEN 100

void censor(char*);
int read_line(char*, int);

int main(void) {
	char msg[MAX_LEN+1];
	printf("Message : "); read_line(msg, MAX_LEN);

	censor(msg);
	printf("Censored message : %s\n", msg);
}

void censor(char* str) {
	if(strlen(str) < 3) return;

	int i = 0;
	while(str[i+3] != '\0') {
		char temp = str[i+3];
		str[i+3] = '\0';
		if(strcmp(&str[i], "foo") == 0) strcpy(&str[i], "xxx");
		str[i+3] = temp;

		i++;
	}
}

int read_line(char* str, int max) {
	int ch, i = 0;
	while((ch = getchar()) != '\n') {
		if(i < max) str[i++] = ch;
	} 
	str[i] = '\0';
	return i;
}