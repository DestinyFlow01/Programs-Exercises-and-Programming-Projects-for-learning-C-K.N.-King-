#include<stdio.h>

int main(void) {
	printf("This program sums a series of integers.\nEnter integers (0 to terminate): ");

	int num = 1, sum = 0; 
	while(num) {
		scanf("%d", &num); sum += num;
	}
	printf("The sum is %d\n", sum);
}