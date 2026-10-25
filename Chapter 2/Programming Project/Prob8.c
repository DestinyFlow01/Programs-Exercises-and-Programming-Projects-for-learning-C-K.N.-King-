#include<stdio.h>

int main(void) {
	float loan, rate, payment; 
	printf("Enter amount of loan: "); scanf("%f", &loan);
	printf("Enter interest rate: "); scanf("%f", &rate);
	printf("Enter monthly payment: "); scanf("%f", &payment);
	
	float balance = loan * (1 + (rate/100.0f) / 12.0f) - payment;
	printf("Balance remaining after first payment: $%.2f\n", balance);
	balance = balance * (1 + (rate/100.0f) / 12.0f) - payment;
	printf("Balance remaining after second payment: $%.2f\n", balance);
	balance = balance * (1 + (rate/100.0f) / 12.0f) - payment;
	printf("Balance remaining after third payment: $%.2f\n", balance);
	
}