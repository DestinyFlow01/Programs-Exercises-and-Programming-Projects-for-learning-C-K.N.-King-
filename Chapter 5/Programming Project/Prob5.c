#include<stdio.h>

int main(void) {
	float income; 
	printf("Income : "); scanf("%f", &income);
	printf("Amount of tax : ");

	if(income < 750) printf("$%f", 0.01 * income);
	else if (income < 2250) printf("$%f", 7.5 + 0.02 * income);
	else if (income < 3750) printf("$%f", 37.5 + 0.03 * income);
	else if (income < 5250) printf("$%f", 82.5 + 0.04 * income);
	else if (income < 7000) printf("$%f", 142.5 + 0.05 * income);
	else printf("$%.2f", 230 + 0.06 * income);

	printf("\n");
}