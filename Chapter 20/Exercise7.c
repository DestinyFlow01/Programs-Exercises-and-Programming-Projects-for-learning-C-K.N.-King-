#include<stdio.h>
#define PRINT(x) printf(#x " = %x\n", x)

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void) {
	unsigned int i = 0x12345678;
	int n = 8; 
	PRINT(rotate_left(i, n));
	PRINT(rotate_right(i, n));
}

unsigned int rotate_left(unsigned int i, int n) {
	if(n < 0) return rotate_right(i, -n);
	else if (n >= sizeof(i) * 8) {
		printf("n is too large"); return i;
	}
	unsigned int rotated_bit = (i & ~(~0u >> n)) >> (sizeof(unsigned int) * 8 - n);
	return (i << n) | rotated_bit;
}

unsigned int rotate_right(unsigned int i, int n) {
	if(n < 0) return rotate_left(i, -n);
	else if (n >= sizeof(i) * 8) {
		printf("n is too large"); return i;
	}
	unsigned int rotated_bit = (i & ~(~0u << n)) << (sizeof(unsigned int) * 8 - n);
	return (i >> n) | rotated_bit;
}