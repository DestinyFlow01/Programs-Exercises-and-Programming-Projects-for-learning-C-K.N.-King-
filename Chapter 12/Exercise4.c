//Implementing stack using external variable
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//Stack variable : 
#define STACK_SIZE 100
int contents[STACK_SIZE] = {0};
int top = 0; 
int* top_ptr = contents; //pointing to contents[0]

//Stack operation : 
bool is_empty(void) {return top_ptr == contents;}
bool is_full(void) {return top_ptr == contents + STACK_SIZE;}
void make_empty(void) {top_ptr = contents;}
void push(int i) {
	if(is_full()) printf("Stack overflow\n");
	else *top_ptr++ = i;
}
int pop(void) {
	if(is_empty()) printf("Stack underflow\n");
	else return *--top_ptr;
	exit(EXIT_FAILURE);
}
void print_stack(void) {
	for(int* p = contents; p < top_ptr; p++) printf("%d ", *p);
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