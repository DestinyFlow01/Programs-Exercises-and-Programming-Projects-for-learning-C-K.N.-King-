#include<stdio.h>
#define N 10

void max_min(int[], int, int*, int*);

int main(void) {
	printf("Enter %d numbers : ", N);
	int a[N];
	for(int* p = a; p < N+a; p++) scanf("%d", p);

	int max, min; 
	max_min(a, N, &max, &min);
	printf("Largest : %d\n", max);
	printf("Smallest : %d\n", min);
}

void max_min(int a[], int n, int* max, int* min) {
	*max = *min = *a;

	for(int* p = a + 1; p<a+n; p++) {
		if(*max < *p) *max = *p;
		else if(*min > *p) *min = *p; 
	}
}