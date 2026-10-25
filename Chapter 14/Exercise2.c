#include<stdio.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))

int main() {
	int a[10];
	printf("Number of element for array a : %d\n", NELEMS(a));
}