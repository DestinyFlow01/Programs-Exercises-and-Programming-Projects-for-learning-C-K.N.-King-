#include<stdio.h>
#include<ctype.h>

int compute_scrabble_value(const char* word);

int main(void) {
	char c; 
	printf("Enter a word : ");

	int sum = 0;
	while((c = getchar()) != '\n') sum += compute_scrabble_value(&c);
	printf("Scribble value : %d\n", sum);
}

int compute_scrabble_value(const char* word) {
	switch(toupper(*word)) {
		case 'A' : case 'E' : case 'I' : case 'L' : case 'N' : 
		case 'O' : case 'R' : case 'S' : case 'T' : case 'U' : return 1;

		case 'D' : case 'G' : return 2; break;
		case 'B' : case 'C' : case 'M' : case 'P' : return 3;
		case 'F' : case 'H' : case 'V' : case 'W' : case 'Y' : return 4; 
		case 'K' : return 5; 
		case 'J' : case 'X' : return 8; 
		case 'Q' : case 'Z' : return 10;
	}
}