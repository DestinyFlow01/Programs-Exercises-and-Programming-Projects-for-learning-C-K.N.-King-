#include<stdio.h>

int main(void) {
	long n, sum = 0;

	puts("This program sums a series of integers.");
	printf("Enter integers (0 to terminate) : ");

	do {
		scanf("%ld", &n);
		sum += n;
	} while(n != 0);

	printf("The sum is %ld\n", sum);
}