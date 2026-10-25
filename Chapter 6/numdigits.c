#include<stdio.h>

int main(void) {
	unsigned int n; 
	printf("Enter a nonnegative integer : "); scanf("%d", &n);

	int num_digit = 0; 
	do {
		num_digit++;
		n /= 10;
	} while(n);

	printf("The number has %d digit", num_digit);
	if (num_digit > 1) printf("(s)");
	printf("\n");
}