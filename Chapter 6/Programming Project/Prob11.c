#include<stdio.h>

int main(void) {
	int n; 
	printf("Enter n : "); scanf("%d", &n);

	unsigned long factorial = 1; 
	float exp = 1; 

	for(int i = 1; i<=n; i++, factorial *= i) exp += 1./factorial;
	printf("e after n = %d terms is %.10f\n", n, exp);
}