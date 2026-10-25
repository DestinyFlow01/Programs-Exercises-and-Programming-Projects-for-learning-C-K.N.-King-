
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_WORD 20
#define SIZE 10

int read_line(char* msg, int n);

int main(void) {
	int capacity = SIZE, num_word = 0;
	char *word = NULL;
	char** database = malloc(sizeof(char*) * capacity);
	if(database == NULL) {
		printf("Malloc fail. No space left. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	while(1) {
		if(num_word >= capacity) {
			//Realloc : 
			capacity *= 2;
			char* new_database = realloc(database, sizeof(char*) * capacity);
			if(new_database == NULL) {
				printf("Realloc fail. No space left. Terminating...\n");
				exit(EXIT_FAILURE);
			}
		}
		word = malloc(sizeof(char) * MAX_WORD);
		printf("Enter word : ");
		read_line(word, MAX_WORD);
		if(strlen(word) == 0) break;
		database[num_word++] = word;
	}

	//Sorting : 
	printf("In sorted order : ");
	for(int i = 0; i<num_word; i++) {
		int min = i;

		for(int j = i+1; j < num_word; j++) {
			if(strcmp(database[j], database[min]) < 0) min = j;
		}

		if(min != i) {
			char* temp = database[min];
			database[min] = database[i];
			database[i] = temp;
		}

		printf("%s ", database[i]);
	}
	printf("\n");
}

int read_line(char* msg, int n) {
	int i = 0, ch; 
	while(isspace(ch = getchar()) && ch != '\n');
	while(ch != EOF && ch != '\n') {
		if(i < n) msg[i++] = ch;
		ch = getchar(); 
	}
	msg[i] = '\0';
	return i;
}