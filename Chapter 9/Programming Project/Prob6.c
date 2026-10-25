#include<stdio.h>

double poly(double x);

int main(void) {
	double x; 
	printf("x = "); scanf("%lf", &x);
	printf("x = %lf\n", poly(x));
}

double poly(double x) {
	double x2 = x*x;
	double x3 = x2*x;
	double x4 = x2*x2;
	double x5 = x2*x3;

	return 3*x5 + 2*x4 - 5*x3 - x2 + 7*x - 6;
}