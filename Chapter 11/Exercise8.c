#include<stdio.h>
#include<stdlib.h>

int* find_largest(int[], int);

int main(void) {
	int n;
	printf("Enter numbers of elements : "); scanf("%d", &n);
	if(n < 1) {
		printf("n must be positive. Terminating...");
		exit(EXIT_FAILURE);
	}
	int a[n];
	printf("Enter %d numbers : ", n);
	for(int i = 0; i<n; i++) scanf("%d", &a[i]);

	int* max = find_largest(a, n);
	printf("Largest = %d\n", *max);
}

int* find_largest(int a[], int n) {
	int idx_max = 0; 
	for(int i = 1; i<n; i++) {
		if(a[idx_max] < a[i]) idx_max = i;
	}
	return &a[idx_max];
}