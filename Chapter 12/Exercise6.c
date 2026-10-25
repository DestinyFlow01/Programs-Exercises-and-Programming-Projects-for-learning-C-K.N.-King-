#include<stdio.h>

int sum_array_old(const int a[], int n) {
	int sum = 0; 
	for(int i = 0; i<n; i++) sum += a[i];
	return sum;
}

int sum_array_new(const int a[], int n) {
	int sum = 0; 
	for(int* p = a; p<a+n; p++) sum += *p;
	return sum;
}