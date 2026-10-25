#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

//Macro : 
#define MAX_DIGITS 10
#define SEGMENTS_COL MAX_DIGITS*4
#define SEGMENTS_ROW 3
char segments[SEGMENTS_ROW][SEGMENTS_COL] = {0};
int last_index = 0, num_digit = 0;

//Function prototype : 
void clear_segments(void);
void process_segments();
void print_segments(void);

int main() {
	clear_segments();
	process_segments();
	print_segments();
}

void clear_segments(void) {
	for(int i = 0; i<SEGMENTS_ROW; i++) {
		for(int j = 0; j < SEGMENTS_COL; j++) segments[i][j] = ' ';
	}
}

void process_segments() {
	printf("Enter a number : "); 

	char ch;
	int num_digit = 0;
	while((ch = getchar()) != '\n' && num_digit < MAX_DIGITS) {
		if(!isdigit((unsigned char) ch)) continue;

		//From here on, they are digits : 
		switch(ch) {
			case '0' : {
				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|'; 

				segments[0][last_index] = '_'; segments[1][last_index] = ' ';
				segments[2][last_index++] = '_'; 

				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|'; break;
			}
			case '1' : {
				segments[0][last_index] = ' '; segments[1][last_index] = ' ';
				segments[2][last_index++] = ' '; 

				segments[0][last_index] = ' '; segments[1][last_index] = ' ';
				segments[2][last_index++] = ' '; 

				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|'; break;
			}
			case '2' : {
				segments[0][last_index] = ' '; segments[1][last_index] = ' ';
				segments[2][last_index++] = '|';

				segments[0][last_index] = '_'; segments[1][last_index] = '_';
				segments[2][last_index++] = '_'; 

				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = ' '; break;
			}
			case '3' : {
				segments[0][last_index] = ' '; segments[1][last_index] = ' ';
				segments[2][last_index++] = ' ';

				segments[0][last_index] = '_'; segments[1][last_index] = '_';
				segments[2][last_index++] = '_'; 

				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|'; break;
			}
			case '4' : {
				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = ' ';

				segments[0][last_index] = ' '; segments[1][last_index] = '_';
				segments[2][last_index++] = ' '; 

				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|'; break;
			}
			case '5' : {
				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = ' ';

				segments[0][last_index] = '_'; segments[1][last_index] = '_';
				segments[2][last_index++] = '_'; 

				segments[0][last_index] = ' '; segments[1][last_index] = ' ';
				segments[2][last_index++] = '|'; break;
			}
			case '6' : {
				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|';

				segments[0][last_index] = '_'; segments[1][last_index] = '_';
				segments[2][last_index++] = '_'; 

				segments[0][last_index] = ' '; segments[1][last_index] = ' ';
				segments[2][last_index++] = '|'; break;
			}
			case '7' : {
				segments[0][last_index] = ' '; segments[1][last_index] = ' ';
				segments[2][last_index++] = ' ';

				segments[0][last_index] = '_'; segments[1][last_index] = ' ';
				segments[2][last_index++] = ' '; 

				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|'; break;
			}
			case '8' : {
				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|';

				segments[0][last_index] = '_'; segments[1][last_index] = '_';
				segments[2][last_index++] = '_'; 

				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|'; break;
			}
			case '9' : {
				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = ' ';

				segments[0][last_index] = '_'; segments[1][last_index] = '_';
				segments[2][last_index++] = '_'; 

				segments[0][last_index] = ' '; segments[1][last_index] = '|';
				segments[2][last_index++] = '|'; break;
			}
			default : exit(EXIT_FAILURE);
		}

		//Printing space : 
		for(int i = 0; i<SEGMENTS_ROW; i++) segments[i][last_index] =' '; 
		last_index++;
		num_digit++;
	}
}

void print_segments(void) {
	for(int i = 0; i<SEGMENTS_ROW; i++) {
		for(int j = 0; j<last_index; j++) {
			printf("%c", segments[i][j]);
		}
		printf("\n");
	}
}