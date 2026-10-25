#include<stdio.h>

#define INITIAL_VALUE 100

int main(void) {
	unsigned int rate, num_year; 

	printf("Enter interest rate : "); scanf("%u", &rate);
	printf("Enter number of years : "); scanf("%u", &num_year);

	double value[5] = {0};
	printf("Years\t");
	for(int i = 0; i<5; i++) {
		printf("%3d%%", rate + i);
		value[i] = INITIAL_VALUE;
	}
	printf("\n");

	for(int year = 0; year<num_year; year++) {
		printf("%3d    ", year + 1); 
		for(int i = 0; i<5; i++) {
			value[i] *= 1 + (rate + i) / 100.;
			printf("%7.2lf", value[i]);
		}
		printf("\n");
	}
}