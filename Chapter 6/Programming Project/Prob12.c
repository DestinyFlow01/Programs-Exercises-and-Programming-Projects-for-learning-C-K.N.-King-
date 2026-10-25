#include<stdio.h>

int main(void) {
	float epsilon; 
	printf("Enter epsilon : "); scanf("%f", &epsilon);

	unsigned long factorial = 1; 
	float exp = 1; 
	float inv_epsilon = 1./epsilon;

	for(int i = 1; factorial <= inv_epsilon ; i++, factorial *= i) exp += 1./factorial;
	printf("e to less than %f threshold is %.10f\n", epsilon, exp);
}