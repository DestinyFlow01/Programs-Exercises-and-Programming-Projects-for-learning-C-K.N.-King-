#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//Stack variable : 
#define STACK_SIZE 100
// #define DEBUG
char contents[STACK_SIZE] = {0};
int top = 0; 

//Stack operation : 
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
char pop(void) {
	if(is_empty()) {
		printf("Stack underflow. Not enough operands in expression\n");
		exit(EXIT_FAILURE);
	}
	else return contents[--top];
}
void print_stack(void) {
	for(int i = 0; i<top; i++) printf("%c ", contents[i]);
	printf("\n");
}

void parentheses_brace(void);

int main(void) {
	#ifdef DEBUG
		printf("Debug on \n\n");
	#endif
	
	printf("Enter parentheses and/or braces : ");
	parentheses_brace();
	exit(EXIT_SUCCESS);
}

void parentheses_brace(void) {
	char ch;

	do{
		ch = getchar();
		if(ch == ' ' || ch == '\n') continue;

		switch(ch) {
			case '(' : case '{' : push(ch); break;
			case ')' : 
				if(is_empty() || pop() != '(') {
					printf("Parentheses/braces are not nested properly\n");
					exit(EXIT_SUCCESS);
				}
				break;
			case '}' :
				if(is_empty() || pop() != '{') {
					printf("Parentheses/braces are not nested properly\n");
					exit(EXIT_SUCCESS);
				}
				break;
			default : exit(EXIT_FAILURE); 
		}
	}while(ch != '\n');

	if(is_empty()) printf("Parentheses/braces are nested properly\n");
	else  printf("Parentheses/braces are not nested properly\n");
}