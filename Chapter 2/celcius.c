#include<stdio.h>
#define SCALE (5.0f/9.0f)
#define FREEZING_PT 32.0f

int main() {
	float celcius, fahrenheit;
	printf("Enter Fahrenheit temperature : "); scanf("%f", &fahrenheit);

	celcius = SCALE * (fahrenheit - FREEZING_PT);
	printf("Celcius equivalent : %.2f\n", celcius);
}