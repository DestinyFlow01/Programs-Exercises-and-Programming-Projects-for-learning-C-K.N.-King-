#include<stdio.h>

int main(void) {
	float speed; 
	printf("Speed (knots) : "); scanf("%f", &speed);
	printf("Description : ");

	if(speed < 1) printf("Calm");
	else if (speed < 4) printf("Light air");
	else if (speed < 28) printf("Breeze");
	else if (speed < 48) printf("Storm");
	else printf("Hurricane");

	printf("\n");
}