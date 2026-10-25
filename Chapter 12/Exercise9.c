#include<stdio.h>
#include<stdlib.h>

double inner_product(const double*, const double*, int);

int main(void) {
	int n; 
	printf("Enter n : "); scanf("%d", &n);
	if(n < 1) {
		printf("n must be positive. Terminating...");
		exit(EXIT_FAILURE);
	}

	double a[n], b[n];
	printf("Enter array a : ");
	for(int i = 0; i<n; i++) scanf("%lf", &a[i]);

	printf("Enter array b : ");
	for(int i = 0; i<n; i++) scanf("%lf", &b[i]);

	printf("Dot product (Scalar product) between a and b = %.3lf\n", 
		inner_product(a, b, n));
}

double inner_product(const double* a, const double* b, int n) {
	double sum = 0; 
	const double *p = a, *q = b;
	for(const double *p = a, *q = b; p < a+n && q < b+n;) sum += *p++ * *q++;
	return sum;
}