#include<stdio.h>

int main(void) {
	printf("Enter an expression : ");
	char oper; double x1, x2;

	//First one must be included first, used as accumulator: 
	scanf("%lf", &x1);

	//Removing unnecessary whitespace : 
	while(getchar() != ' ');

	//The second one involves only 1 operand. Terminate if '\n' is encountered : 
	while( (oper = getchar()) != '\n') {
		scanf(" %lf", &x2);

		if(oper == '+') x1 += x2;
		else if (oper == '-') x1 -= x2;
		else if (oper == '*') x1 *= x2;
		else if (oper == '/') x1 /= x2;
	}

	printf("Value of expression : %.1lf\n", x1);
}