#include<stdio.h>

//Part a : 
typedef struct {
	double real, imaginary;
} Complex;

//Part c : 
Complex make_complex(double real, double imaginary) {
	return (Complex) {.real = real, .imaginary = imaginary};
}

//Part d : 
Complex add_complex(Complex c1, Complex c2) {
	return (Complex) {.real = c1.real + c2.real, .imaginary = c1.imaginary + c2.imaginary};
}

int main(void) {
	//Part b : 
	Complex c1, c2, c3;
}