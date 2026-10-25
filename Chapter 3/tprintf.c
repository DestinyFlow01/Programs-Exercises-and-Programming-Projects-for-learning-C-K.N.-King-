#include<stdio.h>

int main(void) {
	int i = 40; 
	float x = 839.21f;

	printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
	printf("|%10.3f|%10.3e|%-10g|\n\n", x, x, x);


	//Escape sequence : 
	printf("Item\tUnit\tPurchase\n\tPrice\tDate\n\n");
	printf("ABC\bDE\n");
	printf("ALERT \a\n");
}