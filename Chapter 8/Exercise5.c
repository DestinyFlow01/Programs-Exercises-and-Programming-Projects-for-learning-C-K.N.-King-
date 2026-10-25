#include<stdio.h>

#define LENGTH 40

int main(void) {
	unsigned int fib_numbers[LENGTH] = {0};
	fib_numbers[0] = 1;
	fib_numbers[1] = 1;

	for(int i = 2; i<LENGTH; i++) fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
	printf("Fibonanci numbers : ");
	for(int i = 0; i<LENGTH; i++) printf("%u ", fib_numbers[i]);
	printf("\n");
}