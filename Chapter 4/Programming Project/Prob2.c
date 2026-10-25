#include<stdio.h>

int main(void) {
	int a; 
	printf("Enter a three-digit number : "); scanf("%d", &a);
	printf("The reversal is %d%d%d\n",(a%100)%10, (a%100) / 10, a/100);
}