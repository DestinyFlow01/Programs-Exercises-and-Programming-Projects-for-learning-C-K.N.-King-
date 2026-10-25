#include<stdio.h>

//Part a : 
struct complex {
	double real, imaginary;
};

//Part c : 
struct complex make_complex(double real, double imaginary) {
	return (struct complex) {.real = real, .imaginary = imaginary};
}

//Part d : 
struct complex add_complex(struct complex c1, struct complex c2) {
	return (struct complex) {.real = c1.real + c2.real, .imaginary = c1.imaginary + c2.imaginary};
}

int main(void) {
	//Part b : 
	struct complex c1, c2, c3;
}