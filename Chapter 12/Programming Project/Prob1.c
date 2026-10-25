#include<stdio.h>
#include<ctype.h>
#define MAX_LEN 1000

int main(void) {
	char msg[MAX_LEN], ch;
	char* msg_ptr = msg;

	printf("Enter a message : ");
	while(msg_ptr < MAX_LEN + msg && (ch = getchar()) != '\n') 
	*msg_ptr++ = ch;

	printf("Reversal is : ");
	for(char* ptr = msg_ptr-1; ptr >= msg;) printf("%c", *ptr--);
	printf("\n");
}