#include<stdio.h>
#include<stdlib.h>

struct node {
	int value; 
	struct node* next;
};

struct node* add_list(struct node* list, int n) {
	struct node* new_nodes;

	if( (
		new_nodes = malloc(sizeof(struct node));
	) 
	== NULL) {
		printf("Malloc fail, no space left. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	new_nodes->value = n;
	new_nodes->next = list;
	return new_nodes;
}

int main(void) {
	struct node* first = NULL;
	first = add_list(first, 10);
	first = add_list(first, 20);

	printf("First value = %d\n", first->value);
	printf("First->next value = %d\n", first->next->value);
}