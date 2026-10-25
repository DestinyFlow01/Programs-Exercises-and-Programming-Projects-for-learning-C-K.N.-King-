#include<stdio.h>

void swap(int*, int*);

int main(void) {
	printf("Enter 2 numbers : ");
	int p, q; scanf("%d %d", &p, &q);
	swap(&p, &q);
	printf("Swapped : (%d, %p), (%d, %p)\n", p, &p, q, &q);
}

void swap (int* p, int* q) {
	int temp = *p;
	*p = *q; 
	*q = temp;
}