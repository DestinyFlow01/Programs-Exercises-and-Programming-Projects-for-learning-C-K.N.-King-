#include<stdio.h>

int main(void) {
	char ch1, ch2;

	printf("Enter a first and last name : ");
	ch1 = getchar(); //Obtaining the first character only

	//Skipping until encountering space
	while( (ch2 = getchar()) != '\40');

	//Continue to the second one : 
	while( (ch2 = getchar()) != '\n') putchar(ch2);

	printf(", %c.\n", ch1);
}