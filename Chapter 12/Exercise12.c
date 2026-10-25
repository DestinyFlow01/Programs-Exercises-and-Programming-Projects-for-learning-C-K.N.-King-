#include<stdio.h>
#include<stdlib.h>

void find_two_largest(const int*, int, int*, int*);

int main(void) {
	int n; 
	printf("Enter n : "); scanf("%d", &n);
	if(n < 2) {
		printf("n must at least be 2. Terminating...");
		exit(EXIT_FAILURE);
	}

	int a[n];
	printf("Enter array a : ");
	for(int i = 0; i<n; i++) scanf("%ld", &a[i]);

	int largest, second_largest; 
	find_two_largest(a, n, &largest, &second_largest);

	printf("Largest = %d\n", largest); 
	printf("Second larget = %d\n", second_largest);
}

void find_two_largest(const int* a, int n, 
	int* largest, int* second_largest) {
	*largest = *a;

	for(const int* p = a+1; p < a + n; p++) {
		if(*largest < *p) *largest = *p;
	}

	*second_largest = (*largest == *a) ? *(a + 1) : *a;
	for(const int* p = a + 1; p < a + n; p++) {
		if(*second_largest < *p && *p != *largest) *second_largest = *p;
	}
}