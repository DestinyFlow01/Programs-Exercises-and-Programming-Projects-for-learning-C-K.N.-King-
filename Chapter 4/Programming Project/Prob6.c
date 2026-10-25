#include<stdio.h>

int main(void) {
	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12; 

	printf("Enter the first 12 digits of an EAN : "); 
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%ld", &a1, 
	&a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &a11, &a12);
	
	int sum1 = a2 + a4 + a6 + a8 + a10 + a12;
	int sum2 = a1 + a3 + a5 + a7 + a9 + a11;
	printf("Check digit : %d\n", 9 - (3 * sum1 + sum2 - 1) % 10);
}