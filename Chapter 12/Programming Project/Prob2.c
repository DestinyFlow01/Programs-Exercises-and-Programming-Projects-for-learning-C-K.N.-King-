#include<stdio.h>
#include<ctype.h>
#define MAX_LEN 1000

int main(void) {
	char msg[MAX_LEN], ch;
	char* msg_ptr = msg;

	printf("Enter a message : ");
	while(msg_ptr < MAX_LEN + msg && (ch = getchar()) != '\n') {
		if(!isalpha(ch)) continue;
		*msg_ptr++ = ch; //If the char is letter
	}

	//Determining Palindrom : 
	char *msg_ptr_left = msg, *msg_ptr_right = msg_ptr-1;
	while(msg_ptr_left < msg_ptr_right) {
		if(tolower( (unsigned char) *msg_ptr_left++) != tolower((unsigned char) *msg_ptr_right--)) {
			printf("Not a palindrome\n"); 
			return 0;
		}
	}
	printf("Palindrome\n");
}