#include<stdio.h>
#include<stdlib.h>

int* find_middle(int a[], int n) {
	return (a + n/2);
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

	int* middle = find_middle(a, n);
	printf("Middle = %d\n", *middle);
}
