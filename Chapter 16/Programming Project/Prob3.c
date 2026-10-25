#include<stdio.h>
#include "readline.h"

#define MAX_LEN_NAME 100
#define MAX_SIZE 100

struct part {
	char name[MAX_LEN_NAME+1];
	int number; 
	int on_hand;
};

void Insert(struct part[], int*);
void Search(struct part[], int);
void Print(struct part[], int);
void Update(struct part[], int);


int main(void) {
	struct part database[MAX_SIZE];
	int top = 0;

	char ch;
	for(;;) {
		printf("Enter operation code : ");
		scanf(" %c", &ch);
		while(getchar() != '\n');

		switch(ch) {
			case 'i' : Insert(database, &top); break;
			case 's' : Search(database, top); break;
			case 'u' : Update(database, top); break;
			case 'p' : Print(database, top); break;
			case 'q' : return 0;
		}
		printf("\n");
	}
}

int FindIdx(int num, int top, struct part database[]) {
	int idx_found = -1;
	for(int i = 0; i<top; i++) {
		if(database[i].number == num) {
			idx_found = i; break;
		}
	}
	return idx_found;
}

void Insert(struct part database[], int* top) {
	int num;
	printf("Enter part number : "); scanf(" %d", &num);
	if(FindIdx(num, *top, database) == -1 && *top < MAX_SIZE) {
		database[*top].number = num;
		printf("Enter part name : "); read_line(database[*top].name, MAX_LEN_NAME);
		printf("Enter quantity on hand : "); scanf(" %d", &database[*top].on_hand);
		(*top)++;
	}
	else printf("Database is full or part number exists already in the database\n");
}


void Search(struct part database[], int top) {
	int num;
	printf("Enter part number : "); scanf(" %d", &num);
	int idx_found = FindIdx(num, top, database);

	if(idx_found == -1) printf("Part not found\n");
	else {
		printf("Part name : %s\n", database[idx_found].name);
		printf("Quantity on hand : %d\n", database[idx_found].on_hand);
	}
}

void Print(struct part database[], int top) {
	printf("%-15s %-30s %-15s", "Part Number", "Part Name", "Quantity on Hand\n");
	for(int i = 0; i<top; i++) {
		printf("%-15d %-30s %-15d\n", database[i].number, database[i].name, database[i].on_hand);
	}
}

void Update(struct part database[], int top) {
	int num;
	printf("Enter part number : "); scanf(" %d", &num);
	int idx_found = FindIdx(num, top, database);

	if(idx_found == -1) printf("Part not found\n");
	else {
		int change;
		printf("Enter change in quantity on hand : "); scanf(" %d", &change);
		database[idx_found].on_hand += change;
	}
}