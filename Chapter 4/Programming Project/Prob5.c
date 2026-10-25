#include<stdio.h>

int main(void) {
	int type, manuf1, manuf2, manuf3, manuf4, manuf5, prod1, prod2, prod3, prod4, prod5; 

	printf("Enter the first 11 digits of a UPC : "); 
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &type, 
	&manuf1, &manuf2, &manuf3, &manuf4, &manuf5,
	&prod1, &prod2, &prod3, &prod4, &prod5);
	
	int sum1 = type + manuf2 + manuf4 + prod1 + prod3 + prod5;
	int sum2 = manuf1 + manuf3 + manuf5 + prod2 + prod4;
	printf("Check digit : %d\n", 9 - (3 * sum1 + sum2 - 1) % 10);
}