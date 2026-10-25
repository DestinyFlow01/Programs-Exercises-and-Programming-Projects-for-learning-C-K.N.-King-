#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

int contents[STACK_SIZE] = {0};
int top = 0; 

bool is_empty(void) {return top == 0;}
bool is_full(void) {return top == STACK_SIZE;}
void make_empty(void) {top = 0;}
void push(int i) {
	if(is_full()) {
		printf("Stack overflow. Expression is too complex\n");
		exit(EXIT_FAILURE);
	}
	else contents[top++] = i;
}
int pop(void) {
	if(is_empty()) {
		printf("Stack underflow. Not enough operands in expression\n");
		exit(EXIT_FAILURE);
	}
	else return contents[--top];
}
void print_stack(void) {
	for(int i = 0; i<top; i++) printf("%d ", contents[i]);
	printf("\n");
}