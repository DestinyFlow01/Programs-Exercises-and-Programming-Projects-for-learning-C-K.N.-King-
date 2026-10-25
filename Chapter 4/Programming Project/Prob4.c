#include<stdio.h>

int main(void) {
	int a; 
	printf("Enter a number between 0 and 32767 : "); scanf("%d", &a);
	if(a < 0) return 1;

	int oct0, oct1, oct2, oct3, oct4, temp = a;
	oct0 = temp % 8; temp /= 8;
	oct1 = temp % 8; temp /= 8;
	oct2 = temp % 8; temp /= 8;
	oct3 = temp % 8; temp /= 8;
	oct4 = temp % 8;
	
	printf("In octal, your number is %d%d%d%d%d\n", oct4, oct3, oct2, oct1, oct0);
}