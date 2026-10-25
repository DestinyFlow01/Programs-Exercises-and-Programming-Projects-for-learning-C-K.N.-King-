#include<stdio.h>

void avg_sum(double[], int, double*, double*);

int main() {
	int n;
	printf("Enter numbers of elements : "); scanf("%d", &n);
	double a[n];
	printf("Enter %d numbers : ", n);
	for(int i = 0; i<n; i++) scanf("%lf", &a[i]);

	double avg, sum;
	avg_sum(a, n, &avg, &sum);
	printf("Avg = %.3lf, sum = %.3lf\n", avg, sum);
}

void avg_sum(double a[], int n, double* avg, double* sum) {
	*sum = 0; 
	for(int i = 0; i<n; i++) *sum += a[i];
	*avg = *sum / n;
}