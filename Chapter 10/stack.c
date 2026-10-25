//Implementing stack using external variable
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//Stack variable : 
#define STACK_SIZE 100
int contents[STACK_SIZE] = {0};
int top = 0; 

//Stack operation : 
bool is_empty(void) {return top == 0;}
bool is_full(void) {return top == STACK_SIZE;}
void make_empty(void) {top = 0;}
void push(int i) {
	if(is_full()) printf("Stack overflow\n");
	else contents[top++] = i;
}
int pop(void) {
	if(is_empty()) printf("Stack underflow\n");
	else return contents[--top];
	exit(EXIT_FAILURE);
}
void print_stack(void) {
	for(int i = 0; i<top; i++) printf("%d ", contents[i]);
	printf("\n");
}

int main(void) {
	make_empty();
	push(2);
	push(3);
	print_stack();
	pop();
	print_stack();
	pop(); pop();
	print_stack();
}