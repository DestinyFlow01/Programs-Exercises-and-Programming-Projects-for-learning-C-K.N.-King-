#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define MAX_LEN 1000

bool is_palindrome(const char*);

int main(void) {
	char msg[MAX_LEN], ch;
	char* msg_ptr = msg;

	printf("Enter a message : ");
	while(msg_ptr < MAX_LEN + msg && (ch = getchar()) != '\n') {
		if(!isalpha(ch)) continue;
		*msg_ptr++ = ch; //If the char is letter
	}
	*msg_ptr = '\0';

	//Determining Palindrom :
	printf("%s\n", is_palindrome(msg) ? "Palindrome" : "Not a palindrome");
}

bool is_palindrome(const char* message) {
	for(const char* left = message, *right = message + strlen(message) - 1; left < right;) {
		if(tolower( (unsigned char) *left++) != tolower((unsigned char) *right--)) return false;
	}
	return true;
}