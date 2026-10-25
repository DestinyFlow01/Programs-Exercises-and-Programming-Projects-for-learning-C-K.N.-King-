#include<stdio.h>
#include<ctype.h>

int main(void) {
	char ch[99];
	int i = 0; 
	
	printf("Enter phone number : ");

	while((ch[i] = getchar()) != '\n') {
		switch(toupper(ch[i])) {
			case 'A' : case 'B' : case 'C' : printf("2"); break;
			case 'D' : case 'E' : case 'F' : printf("3"); break;
			case 'G' : case 'H' : case 'I' : printf("4"); break;
			case 'J' : case 'K' : case 'L' : printf("5"); break;
			case 'M' : case 'N' : case 'O' : printf("6"); break;
			case 'P' : case 'S' : case 'R' : printf("7"); break;
			case 'V' : case 'T' : case 'U' : printf("8"); break;
			case 'W' : case 'X' : case 'Y' : printf("9"); break;
			default : putchar(ch[i]);
		}
		i++;
	}
	printf("\n");
}