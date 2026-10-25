#include<stdio.h>

int main() {
	int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
	int *p = &a[1], *q = &a[5];

	printf("*(p+3) = %d\n", *(p+3)); //14
	printf("*(q-3) = %d\n", *(q-3)); //34
	printf("q - p = %d\n", q-p); //4
	printf("p < q : %d\n", p < q); //true (1)
	printf("*p < *q : %d\n", *p < *q); //false (0)
}