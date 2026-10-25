#include<stdio.h>

int main(void) {
	int a; 
	printf("Enter a number : "); scanf("%d", &a);
	printf("The reversal is ");

	while(a != 0) {
		printf("%d", a%10);
		a /= 10;
	}
	printf("\n");
}