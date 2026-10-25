#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "readline.h"

#define MAX_NAME_LEN 100

struct part {
	int number; 
	char name[MAX_NAME_LEN + 1];
	int on_hand;
	struct part* next;
};

//Inventory external variable : 
struct part* inventory = NULL;

//Functions : 
void Insert(void);
void Search(void);
void Update(void);
void Print(void);
void Erase(void);

int main(void) {
	int code, ch;
	for(;;) {
		printf("Enter operation code : "); code = getchar();
		while(!isspace(ch = getchar()));
		switch(code) {
			case 'i' : Insert(); break;
			case 's' : Search(); break;
			case 'p' : Print(); break;
			case 'u' : Update(); break;
			case 'e' : Erase(); break;
			case 'q' : return 0;
		}
	}
}

/// @brief Finding Sorted position to insert a new node
/// @param num to be inserted
/// @return Pointer variable, for which the new node will be inserted after it. 
/// If it is NULL, then insert it at the beginning of the linked list
struct part* FindSortedPosition_list(int num) {
	struct part *prev = NULL, *curr = inventory;
	for(; curr != NULL && curr->number < num; prev = curr, curr = curr->next);
	return prev;
}


void Insert(void) {
	struct part *new_node = malloc(sizeof(struct part));
	if(new_node == NULL) {
		printf("Malloc fails. Can't add part due to full storage. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter part number : "); scanf("%d", &new_node->number);
	while(!isspace(getchar()));

	//Checking on the possibility that has existed
	struct part *ptr = inventory;
	for(; ptr != NULL && ptr->number != new_node->number; ptr = ptr->next);
	if(ptr != NULL) {
		printf("Part has existed\n");
	}
	else {
		printf("Enter part name : "); read_line(new_node->name, MAX_NAME_LEN);
		printf("Enter quantity on hand : "); scanf("%d", &new_node->on_hand);
		while(!isspace(getchar()));
	
		//Finding position to be kept : 
		struct part *position = FindSortedPosition_list(new_node->number);
		if(position == NULL) {
			//Inserting at the beginning : 
			new_node->next = inventory;
			inventory = new_node;
		}
		else {
			//Inserting after position : 
			new_node->next = position->next;
			position->next = new_node;
		}
	}
	printf("\n");
}

void Search(void) {
	int num;
	printf("Enter part number : "); scanf("%d", &num);
	while(!isspace(getchar()));

	struct part *ptr = inventory;
	for(; ptr != NULL && ptr->number != num; ptr = ptr->next);

	if(ptr == NULL) printf("Part not found\n");
	else printf("Part name : %s\nQuantity on hand : %d\n", ptr->name, ptr->on_hand);
	printf("\n");
}

void Update(void) {
	int num;
	printf("Enter part number : "); scanf("%d", &num);
	while(!isspace(getchar()));

	int change;
	printf("Enter change in quantity on hand : "); scanf("%d", &change);
	while(!isspace(getchar()));

	struct part *ptr = inventory;
	for(; ptr != NULL && ptr->number != num; ptr = ptr->next);

	if(ptr == NULL) printf("Part not found\n");
	else ptr->on_hand += change;
	printf("\n");
}


void Print(void) {
	printf("%-20s%-50s%-20s\n", "Part Number", "Part Name", "Quantity on Hand");
	if(inventory == NULL) {
		printf("Nothing to be printed\n");
	}
	else {
		for(struct part *ptr = inventory; ptr != NULL; ptr = ptr->next) {
			printf("%-20d%-50s%-20d\n", ptr->number, ptr->name, ptr->on_hand);
		}
	}
	printf("\n");
}

void Erase() {
	int num;
	printf("Enter part number : "); scanf("%d", &num);
	while(!isspace(getchar()));

	//Checking whether part exist or not : 
	struct part *ptr = inventory, *prev = NULL;
	for(; ptr != NULL && ptr->number != num; prev = ptr, ptr = ptr->next);
	if(ptr != NULL) {
		if(prev == NULL) inventory = ptr->next;
		else prev->next = ptr->next;
		free(ptr);
	}
	else {
		printf("Part is not exist");
	}
	printf("\n");
}