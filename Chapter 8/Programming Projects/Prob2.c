#include<stdbool.h>
#include<stdio.h>

int main(void) {
	unsigned int repeated[10] = {0};
	long n;
	int digit;

	printf("Enter a number : ");
	scanf("%lld", &n);

	while(n > 0) {
		digit = n%10;
		repeated[digit]++;
		n /= 10;
	}

	printf("Digit :         ");
	for(int i = 0; i<10; i++) printf("%3d ", i);
	printf("\n");
	printf("Occurrences :   ");
	for(int i = 0; i<10; i++) printf("%3d ", repeated[i]);
	printf("\n");
}