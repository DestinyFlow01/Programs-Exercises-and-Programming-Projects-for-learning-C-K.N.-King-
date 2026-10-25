#include<stdio.h>

int main(void) {
	unsigned int len = 0;
	
	printf("Enter a message : ");
	while(getchar() != '\n') len++;

	printf("Your message was %u characters\n", len);
}