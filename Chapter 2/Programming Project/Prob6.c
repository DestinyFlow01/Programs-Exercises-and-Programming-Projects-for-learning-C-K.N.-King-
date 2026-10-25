#include<stdio.h>

int main(void) {
	float x; 
	printf("x = "); scanf("%f", &x);

	float term1 = (3.0f * x + 2.0f) * x - 5.0f;
	float term2 = ((term1) * x - 1.0f)*x;
	float term = ((term2) * x + 7.0f) * x - 6.0f;

	printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %f\n", term);
}