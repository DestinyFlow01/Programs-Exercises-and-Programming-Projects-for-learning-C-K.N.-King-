#include<stdio.h>

#define DOUBLE(x) 2*x
#define DOUBLE_FIX(x) (2*(x))

int main(void) {
	printf("Not fixed : \n");
	printf("DOUBLE(1+2) = %d\n", DOUBLE(1+2)); //4
	printf("4/DOUBLE(2) = %d\n", 4/DOUBLE(2)); //4

	printf("Fixed : \n");
	printf("DOUBLE(1+2) = %d\n", DOUBLE_FIX(1+2)); //6
	printf("4/DOUBLE(2) = %d\n", 4/DOUBLE_FIX(2)); //1
}