#include<stdio.h>

double power(double, int);

int main(void) {
	double x; printf("x = "); scanf("%lf", &x);
	int n; printf("Power of x = "); scanf("%d", &n);
	if(n < 0) return -1;
	printf("x^n = %.3lf\n", power(x,n));
}

double power(double x, int n) {
	if(n == 0) return 1;

	if(n%2 == 0) {
		double half = power(x,n/2); return half*half;
	}
	else return power(x, n-1) * x;
}