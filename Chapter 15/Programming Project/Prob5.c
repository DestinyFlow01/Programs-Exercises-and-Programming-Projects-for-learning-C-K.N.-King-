#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"stack.h"

// #define DEBUG
void RPN_expr(void);

int main(void) {
	#ifdef DEBUG
		printf("Debug on \n\n");
	#endif
	
	while(!feof(stdin)) {
		printf("Enter an RPN expression : ");
		RPN_expr();
	}
}

void RPN_expr(void) {
	char ch;

	while( scanf(" %c", &ch) == 1) {

		switch(ch) {
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
	}
	
}