#include<stdio.h>
#include "quicksort.h"
#define N 10


int main() {
	int a[N];
	printf("Enter 10 numbers to be sorted : ");
	for(int i = 0; i<N; i++) scanf("%d", &a[i]);

	//Sorting : 
	QuickSort(a, 0, N-1);

	//Print result : 
	printf("In sorted order : ");
	for(int i = 0; i<N; i++) printf("%d ", a[i]);
	printf("\n");
}