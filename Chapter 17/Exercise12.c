#include<stdlib.h>

struct node {
	int value; 
	struct node* next;
};

struct node* find_last(struct node* list, int n) {
	struct node* prev = NULL;
	for(; list != NULL; list = list->next) {
		if(list->value == n) prev = list;
	}
	return prev;
}