#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

//Stack variable : 
#define STACK_SIZE 100
// #define DEBUG
int contents[STACK_SIZE] = {0};
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

void RPN_expr(const char*);

int main(void) {
	#ifdef DEBUG
		printf("Debug on \n\n");
	#endif
	
	while(!feof(stdin)) {
		printf("Enter an RPN expression : ");
		char exp[STACK_SIZE + 1] = {'\0'};
		int ch, idx = 0;
		while( (ch = getchar()) != '\n' && idx < STACK_SIZE) {
			if(!isspace(ch)) exp[idx++] = ch;	
		} 
		exp[idx] = '\0';
		RPN_expr(exp);
	}
}

void RPN_expr(const char* expression) {
	while(*expression != '\0') {
		switch(*expression) {
			case '0' : push(0); break;
			case '1' : push(1); break;
			case '2' : push(2); break;
			case '3' : push(3); break;
			case '4' : push(4); break;
			case '5' : push(5); break;
			case '6' : push(6); break;
			case '7' : push(7); break;
			case '8' : push(8); break;
			case '9' : push(9); break;
			case '*' : {
				int oper1 = pop(); 
				int oper2 = pop();
				push(oper1 * oper2); break;
			}
			case '+' : {
				int oper1 = pop(), oper2 = pop();
				push(oper1 + oper2); break;
			}
			case '-' : {
				int oper1 = pop(), oper2 = pop();
				push(oper2 - oper1); break;
			}
			case '/' : {
				int oper1 = pop(), oper2 = pop();
				if(oper1 == 0) {
					printf("Division by 0 detected. Terminating...");
					exit(EXIT_FAILURE);
				}
				push(oper2 / oper1); break;
			}
			case '=' : {
				printf("Value of expression : %d\n", pop());
				if(feof(stdin)) exit(EXIT_SUCCESS); 
				make_empty();
				return;
			}
			case 'q' : exit(EXIT_SUCCESS);
			default : exit(EXIT_FAILURE); 
		}
		expression++;
	}
	
}