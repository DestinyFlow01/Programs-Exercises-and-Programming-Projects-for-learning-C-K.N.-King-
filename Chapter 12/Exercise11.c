#include<stdio.h>
#include<stdlib.h>

int find_largest(int a[], int n) {
	int* max = a; 
	for(int* p = a + 1; p < a + n; p++) {
		if(*max < *p) *max = *p;
	}
	return *max;
}

int main(void) {
		int n; 
	printf("Enter n : "); scanf("%d", &n);
	if(n < 1) {
		printf("n must be positive. Terminating...");
		exit(EXIT_FAILURE);
	}

	int a[n];
	printf("Enter array a : ");
	for(int i = 0; i<n; i++) scanf("%ld", &a[i]);

	int largest = find_largest(a, n);
	printf("Largest = %d\n", largest);
}