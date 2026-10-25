#include<stdio.h>

void store_zeros_old(int a[], int n) {
	for(int i = 0; i<n; i++) a[i] = 0;
}

void store_zeros_new(int a[], int n) {
	for(int* p = a; p<a+n; p++) *p = 0;
}
