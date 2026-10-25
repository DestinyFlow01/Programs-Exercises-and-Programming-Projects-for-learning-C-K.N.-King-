#include<stdio.h>

int main(void) {
	double n;

	printf("Enter a positive number : "); scanf("%lf", &n);
	if(n < 0) return -1;

	double sqrt = 1, error, tolerance = 1e-5;
	do {
		double old_val = sqrt;
		sqrt = 0.5*(sqrt + n/sqrt);
		error = (old_val > sqrt) ? old_val - sqrt : sqrt - old_val;
	} while(error > tolerance);
	printf("Square root : %lf\n", sqrt);
}