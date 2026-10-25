#include<stdio.h>

int main(void) {
	int type, manuf1, manuf2, manuf3, manuf4, manuf5, prod1, prod2, prod3, prod4, prod5, check; 

	printf("Enter the first (single) digit : "); scanf("%1d", &type);
	printf("Enter first group of five digits : "); scanf("%1d%1d%1d%1d%1d", 
		&manuf1, &manuf2, &manuf3, &manuf4, &manuf5);
	printf("Enter second group of five digits : "); scanf("%1d%1d%1d%1d%1d", 
		&prod1, &prod2, &prod3, &prod4, &prod5);
	printf("Check digit : "); scanf("%1d", &check);
	
	int sum1 = type + manuf2 + manuf4 + prod1 + prod3 + prod5;
	int sum2 = manuf1 + manuf3 + manuf5 + prod2 + prod4;
	
	// printf("Check digit : %d\n", 9 - (3 * sum1 + sum2 - 1) % 10);

	if(check == 9 - (3 * sum1 + sum2 - 1) % 10) printf("VALID\n"); 
	else printf("NOT VALID\n");
}