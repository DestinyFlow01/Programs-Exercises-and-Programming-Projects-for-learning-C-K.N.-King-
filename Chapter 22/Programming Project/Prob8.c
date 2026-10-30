#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "readline.h"

#define MAX_LEN_NAME 100
#define MAX_SIZE 100

struct part {
	char name[MAX_LEN_NAME+1];
	int number; 
	int on_hand;
} database[MAX_SIZE];
int top = 0; 


void Insert();
void Search();
void Print();
void Update();
void Save();
void Load();


int main(void) {
	char ch;
	for(;;) {
		printf("Enter operation code : ");
		scanf(" %c", &ch);
		while(getchar() != '\n');

		switch(ch) {
			case 'i' : Insert(); break;
			case 's' : Search(); break;
			case 'u' : Update(); break;
			case 'p' : Print(); break;
			case 'd' : Save(); break;
			case 'r' : Load(); break; 
			case 'q' : return 0;
		}
		printf("\n");
	}
}

int FindIdx(int num) {
	int idx_found = -1;
	for(int i = 0; i<top; i++) {
		if(database[i].number == num) {
			idx_found = i; break;
		}
	}
	return idx_found;
}

void Insert() {
	int num;
	printf("Enter part number : "); scanf(" %d", &num);
	if(FindIdx(num) == -1 && top < MAX_SIZE) {
		database[top].number = num;
		printf("Enter part name : "); read_line(database[top].name, MAX_LEN_NAME);
		printf("Enter quantity on hand : "); scanf(" %d", &database[top].on_hand);
		top++;
	}
	else printf("Database is full or part number exists already in the database\n");
}


void Search() {
	int num;
	printf("Enter part number : "); scanf(" %d", &num);
	int idx_found = FindIdx(num);

	if(idx_found == -1) printf("Part not found\n");
	else {
		printf("Part name : %s\n", database[idx_found].name);
		printf("Quantity on hand : %d\n", database[idx_found].on_hand);
	}
}

void Print() {
	printf("%-15s %-30s %-15s", "Part Number", "Part Name", "Quantity on Hand\n");
	for(int i = 0; i<top; i++) {
		printf("%-15d %-30s %-15d\n", database[i].number, database[i].name, database[i].on_hand);
	}
}

void Update() {
	int num;
	printf("Enter part number : "); scanf(" %d", &num);
	int idx_found = FindIdx(num);

	if(idx_found == -1) printf("Part not found\n");
	else {
		int change;
		printf("Enter change in quantity on hand : "); scanf(" %d", &change);
		database[idx_found].on_hand += change;
	}
}

void Save() {
	printf("Enter name of output file (at most %d characters) : ", MAX_LEN_NAME); 
	char* filename_output = malloc(sizeof(char) * MAX_LEN_NAME);
	if(filename_output == NULL) {
		fprintf(stderr, "Malloc output filename fails. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	
	if(fgets(filename_output, MAX_LEN_NAME, stdin) == NULL) {
		fprintf(stderr, "fgets during saving fails. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	filename_output[strcspn(filename_output, "\n")] = '\0';
	FILE* fp = fopen(filename_output, "wb");
	if(fp == NULL) {
		fprintf(stderr, "Filename %s fails to open. Terminating...\n", filename_output);
		free(filename_output);
		exit(EXIT_FAILURE);
	}

	//Writing top into binary file : 
	fwrite(&top, sizeof(top), 1, fp);

	//Writing struct into binary file :
	for(int i = 0; i<top; i++) {
		fwrite(database[i].name, sizeof(database[i].name), 1, fp);
		fwrite(&database[i].number, sizeof(database[i].number), 1, fp);
		fwrite(&database[i].on_hand, sizeof(database[i].on_hand), 1, fp);
	}
	fclose(fp);
	free(filename_output);
}

void Load() {
	printf("Enter name of input file (at most %d characters) : ", MAX_LEN_NAME); 
	char* filename_input = malloc(sizeof(char) * MAX_LEN_NAME);
	if(filename_input == NULL) {
		fprintf(stderr, "Malloc input filename fails. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	
	if(fgets(filename_input, MAX_LEN_NAME, stdin) == NULL) {
		fprintf(stderr, "fgets during saving fails. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	filename_input[strcspn(filename_input, "\n")] = '\0';
	FILE* fp = fopen(filename_input, "rb");
	if(fp == NULL) {
		fprintf(stderr, "Filename %s fails to open. Terminating...\n", filename_input);
		free(filename_input);
		exit(EXIT_FAILURE);
	}

	//Reading binary file for struct :
	if(fread(&top, sizeof(top), 1, fp) != 1) {
			fprintf(stderr, "Reading number of parts is not full. Terminating...\n");
			exit(EXIT_FAILURE);
	}
	printf("Top = %d\n", top);

	//Reading binary file into struct : 
	for(int i = 0; i < top; i++) {
		if(fread(database[i].name, sizeof(database[i].name), 1, fp) != 1) {
			fprintf(stderr, "Reading part name is not full. Terminating...\n");
			exit(EXIT_FAILURE);
		}

		if(fread(&database[i].number, sizeof(database[i].number), 1, fp) != 1) {
			fprintf(stderr, "Reading number of parts is not full. Terminating...\n");
			exit(EXIT_FAILURE);
		}

		if(fread(&database[i].on_hand, sizeof(database[i].on_hand), 1, fp) != 1) {
			fprintf(stderr, "Reading on_hands of parts is not full. Terminating...\n");
			exit(EXIT_FAILURE);
		}
	}
	fclose(fp);
	free(filename_input);
}