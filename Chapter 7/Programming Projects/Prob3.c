#include<stdio.h>

int main(void) {
	double n, sum = 0;

	puts("This program sums a series of doubles.");
	printf("Enter doubles (0 to terminate) : ");

	do {
		scanf("%lf", &n);
		sum += n;
	} while(n != 0);

	printf("The sum is %lf\n", sum);
}