#include<stdio.h>
#include<ctype.h>

#define MAX_LEN 100

void encrypt(char*, unsigned int);

int main() {
	char msg[MAX_LEN], encrypted[MAX_LEN];
	unsigned int length_msg = 0, shift; 
	char ch;

	printf("Enter message to be encrypted : "); 
	while((ch = getchar()) != '\n') msg[length_msg++] = ch;
	msg[length_msg] = '\0';

	printf("Enter shift amount (1-25) : "); 
	scanf("%u", &shift);
	if(shift > 25 && shift < 1) return -1;

	encrypt(msg, shift);
	printf("Encrypted message : ");
	for(char* msg_ptr = msg; *msg_ptr != '\0'; msg_ptr++) printf("%c", *msg_ptr);
	printf("\n");
}

void encrypt(char *message, unsigned int shift) {
	for(char* msg_ptr = message; *msg_ptr != '\0'; msg_ptr++) {
		if(*msg_ptr >= 'A' && *msg_ptr <= 'Z') {
			*msg_ptr = (*msg_ptr + shift - 'A')%26 + 'A';
		}
		else if(*msg_ptr >= 'a' && *msg_ptr <= 'z') {
			*msg_ptr = (*msg_ptr + shift - 'a')%26 + 'a';
		} 
	}
}

//y : z a b
//24 : 25 0 1 (shift = 3)
//24 + 3 = 27%26 = 1 + 'A'