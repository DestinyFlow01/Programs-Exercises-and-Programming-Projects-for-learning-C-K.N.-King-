#include<stdio.h>

int main(void) {
	int dollar; 
	printf("Enter a dollar amount: "); scanf("%d", &dollar);

	//20 dollar : 
	int num_20 = dollar/20;
	dollar -= num_20 * 20;
	
	//10 dollar : 
	int num_10 = dollar/10;
	dollar -= num_10 * 10;
	
	//5 dollar : 
	int num_5 = dollar/5;
	dollar -= num_5 * 5;
	
	//1 dollar : 
	int num_1 = dollar;
	
	printf("$20 bills: %d\n", num_20);
	printf("$10 bills: %d\n", num_10);
	printf("$5 bills: %d\n", num_5);
	printf("$1 bills: %d\n", num_1);
}