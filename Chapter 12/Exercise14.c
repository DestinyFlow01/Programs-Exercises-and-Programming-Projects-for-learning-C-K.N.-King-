#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool search(const int[], int, int);

int main(void) {
	int temperatures[7][24]; 
	printf("Enter %d numbers : ", n);
	for(int* p = temperatures[0]; p < temperatures[7]; p++) scanf("%d", p);
	
	bool found = search(temperatures, 7*24, 32);
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