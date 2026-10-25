#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int num1, denom1, num2, denom2, result_num, result_denum;
	char oper;

	printf("Enter two fractions separated by an arithmetic sign: "); 
	scanf("%d/%d %c %d/%d", &num1, &denom1, &oper, &num2, &denom2);

	if(oper == '+') {
		result_num = num1 * denom2 + num2 * denom1;
		result_denum = denom1 * denom2;
	}
	else if (oper == '-') {
		result_num = num1 * denom2 - num2 * denom1;
		result_denum = denom1 * denom2;
	}
	else if (oper == '*') {
		result_num = num1 * num2; 
		result_denum = denom1 * denom2;
	}
	else if (oper == '/') {
		result_num = num1 * denom2;
		result_denum = num2 * denom1;
	}
	else {
		printf("Operator not accepted. Terminating : ");
		exit(1);
	}
	

	printf("The result is %d/%d\n", result_num, result_denum);
}