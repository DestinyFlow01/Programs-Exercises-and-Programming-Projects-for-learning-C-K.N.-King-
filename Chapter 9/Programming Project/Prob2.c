#include<stdio.h>

float tax_due (float);

int main(void) {
	float income; 
	printf("Income : "); scanf("%f", &income);
	printf("Amount of tax : %.2f\n", tax_due(income));

	

	printf("\n");
}

float tax_due(float income) {
	if(income < 750) return 0.01 * income;
	else if (income < 2250) return 7.5 + 0.02 * income;
	else if (income < 3750) return 37.5 + 0.03 * income;
	else if (income < 5250) return 82.5 + 0.04 * income;
	else if (income < 7000) return 142.5 + 0.05 * income;
	else return 230 + 0.06 * income;
}