#include<stdio.h>
#include<stdlib.h>

void pay_amount(int, int*, int*, int*, int*);

int main(void) {
	int dollar; 
	printf("Enter a dollar amount: "); scanf("%d", &dollar);
	if(dollar <= 0) {
		printf("Dollar must be positive. Terminating... \n");
		exit(EXIT_FAILURE);
	}

	int num_20, num_10, num_5, num_1;
	pay_amount(dollar, &num_20, &num_10, &num_5, &num_1);
	
	printf("$20 bills: %d\n", num_20);
	printf("$10 bills: %d\n", num_10);
	printf("$5 bills: %d\n", num_5);
	printf("$1 bills: %d\n", num_1);
}

void pay_amount(int dollars, int* twenties, int* tens, int* fives, int* ones) {
	//20 dollar : 
	*twenties = dollars/20;
	dollars -= *twenties * 20;
	
	//10 dollar : 
	*tens = dollars/10;
	dollars -= *tens * 10;
	
	//5 dollar : 
	*fives = dollars/5;
	dollars -= *fives * 5;
	
	//1 dollar : 
	*ones = dollars;
}