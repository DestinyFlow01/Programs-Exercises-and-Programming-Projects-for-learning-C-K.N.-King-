#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_LEN 1000

void reverse(char*);

int main(void) {
	char msg[MAX_LEN], ch;
	char* msg_ptr = msg;

	printf("Enter a message : ");
	while(msg_ptr < MAX_LEN + msg && (ch = getchar()) != '\n') *msg_ptr++ = ch;
	*msg_ptr = '\0';

	printf("Reversal is : ");
	reverse(msg);
}

void reverse(char* message) {
	for(char* ptr = message + strlen(message) - 1; ptr >= message;) printf("%c", *ptr--);
	printf("\n");
}