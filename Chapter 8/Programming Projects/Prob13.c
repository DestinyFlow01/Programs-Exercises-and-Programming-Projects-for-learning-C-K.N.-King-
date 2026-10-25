#include<stdio.h>

int main(void) {
	char ch_first, ch_last[20];

	printf("Enter a first and last name : ");
	//Getting only the first character, the other chars won't be used
	ch_first = getchar(); 	

	//Removing other chars :
	char ch; 
	while((ch = getchar()) != ' ');

	//Accessing last name :
	int i = 0; 
	while( (ch = getchar()) != '\n') ch_last[i++] = ch;

	printf("You entered the name : ");
	for(int idx = 0; idx < i; idx++) putchar(ch_last[idx]);
	printf(", %c.\n", ch_first);
}