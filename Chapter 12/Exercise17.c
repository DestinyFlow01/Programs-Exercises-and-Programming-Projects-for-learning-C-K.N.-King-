#include<stdio.h>
#define LEN 10

int sum_two_dimensional_array_old(const int a[][LEN], int n) {
	int i, j, sum = 0; 
	for(i = 0; i<n; i++) {
		for(j = 0; j<LEN; j++) sum += a[i][j];
	}
	return sum;
}

int sum_two_dimensional_array_new(const int a[][LEN], int n) {
	int sum = 0;
	for(const int *p = a[0]; p < a[n]; p++) sum += *p;
	return sum;
}