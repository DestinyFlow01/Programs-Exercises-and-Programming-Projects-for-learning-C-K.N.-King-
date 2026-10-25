#include<stdio.h>
#include<ctype.h>

int main(void) {
	char ch; 
	printf("Enter a sentence : ");
	
	int sum = 0; 
	while( (ch = getchar()) != '\n') {
		switch(tolower(ch)) {
			case 'a' : case 'e' : case 'o' : case 'i' : case 'u' : sum++; break;
		}
	}

	printf("Your sentence contains %d vowels\n", sum);
}