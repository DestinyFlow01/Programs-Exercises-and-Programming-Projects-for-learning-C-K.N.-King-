#include<stdio.h>

union {
	float value;
	struct {
		unsigned fraction : 23;
		unsigned exponent : 8;
		unsigned sign : 1;
	} representation;
} float_bit;

int main(void) {
	float_bit.representation.sign = 1;
	float_bit.representation.exponent = 128;
	float_bit.representation.fraction = 0;
	printf("Float = %g\n", float_bit.value);
}