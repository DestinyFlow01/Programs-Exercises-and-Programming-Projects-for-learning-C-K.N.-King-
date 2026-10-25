#include<stdio.h>
#include<stdlib.h>

void find_two_largest(int[], int, int*, int*);

int main(void) {
	int n;
	printf("Enter numbers of elements : "); scanf("%d", &n);
	if(n < 2) {
		printf("The number of elements in the array must at least 2. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	int a[n];
	printf("Enter %d numbers : ", n);
	for(int i = 0; i<n; i++) scanf("%ld", &a[i]);

	int largest, second_largest;
	find_two_largest(a, n, &largest, &second_largest);
	printf("Largest = %d, second largest = %d\n", largest, second_largest);
}

void find_two_largest(int a[], int n, int* largest, int* second_largest) {
	if(n == 2) {
		*largest = (a[0] < a[1]) ? a[1] : a[0];
		*second_largest = (a[0] < a[1]) ? a[0] : a[1];
		return;
	}
	*largest = a[0];
	int idx_largest = 0; 

	for(int i = 1; i<n; i++) {
		if(*largest < a[i]) {
			*largest = a[i]; idx_largest = i;
		} 
	}
	
	*second_largest = (idx_largest == 0) ? a[1] : a[0]; 
	for(int i = 1; i<n; i++) {
		if(*second_largest < a[i] && i != idx_largest) *second_largest = a[i];
	}
	
}