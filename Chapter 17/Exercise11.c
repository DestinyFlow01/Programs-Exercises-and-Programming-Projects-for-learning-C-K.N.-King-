#include<stdlib.h>

struct node {
	int value; 
	struct node* next;
};

int count_occurrences(struct node* list, int n) {
	int num = 0; 
	for(; list != NULL; list = list->next) {
		if(list->value == n) num++;
	}
	return num;
}