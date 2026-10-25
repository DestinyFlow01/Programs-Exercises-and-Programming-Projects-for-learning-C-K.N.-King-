#include<stdio.h>
#define N 10

void max_min(int[], int, int*, int*);

int main(void) {
	printf("Enter %d numbers : ", N);
	int a[N];
	for(int i = 0; i<N; i++) scanf("%d", &a[i]);

	int max, min; 
	max_min(a, N, &max, &min);
	printf("Largest : %d\n", max);
	printf("Smallest : %d\n", min);
}

void max_min(int a[], int n, int* max, int* min) {
	*max = *min = a[0];

	for(int i = 1; i<n; i++) {
		if(*max < a[i]) *max = a[i];
		else if(*min > a[i]) *min = a[i]; 
	}
}