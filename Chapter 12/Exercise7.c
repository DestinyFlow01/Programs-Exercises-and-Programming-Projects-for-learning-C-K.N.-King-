#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool search(const int[], int, int);

int main(void) {
	int n; printf("n = "); scanf("%d", &n);
	int a[n]; 
	printf("Enter %d numbers : ", n);
	for(int i = 0; i<n; i++) scanf("%d", &a[i]);
	
	int key; 
	printf("Enter key to be searched : "); scanf("%d", &key);
	bool found = search(a, n, key);
	
	printf("Found = %d\n", found);
}

bool search(const int a[], int n, int key) {
	for(const int* p = a; p < a+n; p++) {
		if(key == *p) {
			printf("Key %d is found at index %d\n", key, p-a);
			return true;
		}
	}
	return false;
}