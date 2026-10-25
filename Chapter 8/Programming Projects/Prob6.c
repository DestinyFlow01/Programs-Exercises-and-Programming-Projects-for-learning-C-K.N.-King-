#include<stdio.h>
#include<ctype.h>

#define SIZE 1000
int main() {
	char message[SIZE] = {'\0'};
	char ch;
	int index = 0;

	printf("Enter message : "); 
	while( (ch = getchar()) != '\n') {
		message[index] = ch;
		index++;

		if(index >= SIZE) break;
	}

	printf("In B1FF-speak : ");
	for(int i = 0; i<index; i++) {
		ch = toupper(message[i]);
		switch (ch) {
			case 'A' : printf("4"); break;
			case 'B' : printf("8"); break;
			case 'E' : printf("3"); break;
			case 'I' : printf("1"); break;
			case 'O' : printf("0"); break;
			case 'S' : printf("5"); break;
			default : putchar(ch);
		}
	}

	for(int i = 0; i<10; i++) printf("!");
	printf("\n");
}