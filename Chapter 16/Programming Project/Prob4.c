#include<stdio.h>
#include "readline.h"

#define MAX_LEN_NAME 100
#define MAX_SIZE 100

struct part {
	char name[MAX_LEN_NAME+1];
	int number; 
	int on_hand;
	double price;
} database[MAX_SIZE];
int top = 0; 


void Insert();
void Search();
void Print();
void Update_Quantity();
void Update_Price();

int main(void) {
	char ch;
	for(;;) {
		printf("Enter operation code : ");
		scanf(" %c", &ch);
		while(getchar() != '\n');

		switch(ch) {
			case 'i' : Insert(); break;
			case 's' : Search(); break;
			case 'u' : Update_Quantity(); break;
			case 'p' : Print(); break;
			case 'c' : Update_Price(); break;
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
		printf("Enter part price : "); scanf(" %lf", &database[top].price);
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
		printf("Part price : %lf\n", database[idx_found].price);
	}
}

void Print() {
	printf("%-15s %-30s %-15s %-15s", "Part Number", "Part Name", "Part Price", "Quantity on Hand\n");
	for(int i = 0; i<top; i++) {
		printf("%-15d %-30s %-15.2lf %-15d\n", database[i].number, database[i].name, database[i].price, database[i].on_hand);
	}
}

void Update_Quantity() {
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

void Update_Price() {
	int num;
	printf("Enter part number : "); scanf(" %d", &num);
	int idx_found = FindIdx(num);

	if(idx_found == -1) printf("Part not found\n");
	else {
		int change;
		printf("Enter change in quantity price : "); scanf(" %d", &change);
		database[idx_found].price = change;
	}
}