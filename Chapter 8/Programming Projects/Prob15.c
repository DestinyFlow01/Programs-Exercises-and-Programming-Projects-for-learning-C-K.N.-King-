#include<stdio.h>
#include<ctype.h>

int main() {
	char msg[100], encrypted[100];
	unsigned int length_msg = 0, shift; 
	char ch;

	printf("Enter message to be encrypted : "); 
	while((ch = getchar()) != '\n') {
		msg[length_msg] = ch;
		length_msg++;
	}

	printf("Enter shift amount (1-25) : "); 
	scanf("%u", &shift);

	printf("Encrypted message : ");
	for(unsigned int i = 0; i<length_msg; i++) {
		if(msg[i] >= 'A' && msg[i] <= 'Z') {
			encrypted[i] = (msg[i] + shift - 'A')%26 + 'A';
		}
		else if(msg[i] >= 'a' && msg[i] <= 'z') {
			encrypted[i] = (msg[i] + shift - 'a')%26 + 'a';
		} 
		else encrypted[i] = msg[i];
		
		printf("%c", encrypted[i]); 
	}
	printf("\n");
}

//y : z a b
//24 : 25 0 1 (shift = 3)
//24 + 3 = 27%26 = 1 + 'A'