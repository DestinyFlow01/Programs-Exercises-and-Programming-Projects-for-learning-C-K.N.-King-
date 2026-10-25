#include<stdio.h>


void selection_sort(int[], int);

int main(void) {
	int n; 
	printf("Number of elements : "); scanf("%d", &n);

	int a[n];
	printf("Enter %d elements : ", n);
	for(int i = 0; i<n; i++) scanf("%d", &a[i]);

	selection_sort(a, n);
	printf("Sorted array : ");
	for(int i = 0; i<n; i++) printf("%d ", a[i]);
	printf("\n");
}

void selection_sort(int a[], int n) {
	if(n == 1) return;

	int max = a[0], max_index = 0;
	for(int i = 1; i<=n-1; i++) {
		max_index = (max < a[i]) ? i : max_index;
		max = (max < a[i]) ? a[i] : max;
	} 
	
	int temp = a[n-1];
	a[n-1] = max;
	a[max_index] = temp;

	selection_sort(a, n-1);
}