#include<stdio.h>

int main(void) {
	float num = 1, max = 0;

	while(num > 0) {
		printf("Enter a number : "); scanf("%f", &num);
		max = (max < num) ? num : max;
	}
	printf("The largest number entered was %.2f\n", max);
}