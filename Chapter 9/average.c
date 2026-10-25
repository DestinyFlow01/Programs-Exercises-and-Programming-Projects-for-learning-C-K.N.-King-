#include<stdio.h>

double average(double x, double y) {return (x+y) / 2;}

int main(void) {
	double x, y, z;

	printf("Enter 3 numbers : "); scanf("%lf%lf%lf", &x, &y, &z);

	printf("Average of %lg and %lg : %lg\n", x, y, average(x,y));
	printf("Average of %lg and %lg : %lg\n", x, z, average(x,z));
	printf("Average of %lg and %lg : %lg\n", z, y, average(z,y));
}