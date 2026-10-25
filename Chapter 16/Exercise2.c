#include<stdio.h>

struct complex {
	double real, imaginary;
} c1 = {0, 1}, 
c2 = {1, 0}, 
c3;

void PrintStruct(struct complex, char*);

int main(void) {
	//Part c : 
	c1 = c2;

	//Part d : 
	c3.real = c1.real + c2.real;
	c3.imaginary = c1.imaginary + c2.imaginary;

	PrintStruct(c1, "c1");
	PrintStruct(c2, "c2");
	PrintStruct(c3, "c3");
}

void PrintStruct(struct complex number, char* msg) {
	printf("%s : Real = %.lf, Imaginary = %.lf\n", msg, number.real, number.imaginary);
}