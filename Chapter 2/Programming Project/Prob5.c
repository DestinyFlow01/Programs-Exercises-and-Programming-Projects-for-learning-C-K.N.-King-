#include<stdio.h>

int main(void) {
	float x; 
	printf("x = "); scanf("%f", &x);

	float x2 = x*x, x3 = x2 * x, x4 = x2 * x2, x5 = x2 * x3;
	printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %f\n", 3*x5 + 2*x4 - 5*x3 - x2 + 7*x - 6);
}