#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD 20

int main(void) {
	char animal[MAX_WORD+1], smallest[MAX_WORD+1], largest[MAX_WORD+1];
	int first = 0;
	while(1) {
		int ch, i = 0; 
		//Receiving input : 
		printf("Enter word : ");
		while((ch = getchar()) != '\n' && i < MAX_WORD) animal[i++] = ch;
		animal[i] = '\0';

		if(first == 0) {
			strcpy(smallest, animal);
			strcpy(largest, animal);
			smallest[strlen(smallest)] = '\0';
			largest[strlen(largest)] = '\0';
			first++;
		}
		else {
			if(strcmp(smallest, animal) > 0) strcpy(smallest, animal);
			if(strcmp(largest, animal) < 0) strcpy(largest, animal);

			smallest[strlen(smallest)] = '\0';
			largest[strlen(largest)] = '\0';
		}

		if(i == 4) break;
	}

	printf("Smallest = %s\nLargest = %s\n", smallest, largest);
}