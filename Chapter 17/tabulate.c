#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void tabulate( double (*)(double), double, double, double );

int main(void) {
	double start, end, increment;
	printf("Enter initial value : "); scanf("%lf", &start);
	printf("Enter final value : "); scanf("%lf", &end);
	if(start >= end) {
		printf("Start must be lower than end. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter increment : "); scanf("%lf", &increment);
	if(increment <= 0) {
		printf("Increment must be positive");
	}

	printf("\n%-10s  %-10s\n", "x", "sin(x)");
	printf("----------  ----------\n");
	tabulate(sin, start, end, increment);

	printf("\n%-10s  %-10s\n", "x", "cos(x)");
	printf("----------  ----------\n");
	tabulate(cos, start, end, increment);

	printf("\n%-10s  %-10s\n", "x", "tan(x)");
	printf("----------  ----------\n");
	tabulate(tan, start, end, increment);
}

void tabulate(double (*f)(double), double start, double end, double increment) {
	for(double x = start; x <= end; x += increment) {
		printf("%-10.5lf  %-10.5lf\n", x, f(x));
	}
}