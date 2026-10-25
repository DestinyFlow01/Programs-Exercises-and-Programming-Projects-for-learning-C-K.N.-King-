#include<stdio.h>
#define PRINT(x) printf(#x " = %x\n", x)

unsigned int reverse_bits(unsigned int n);

int main(void) {
	unsigned int num; 
	printf("Enter number in hex (32 bits) : "); scanf("%x", &num);
	PRINT(reverse_bits(num));
}

unsigned int reverse_bits(unsigned int n) {
	unsigned int reversed = 0u;
	unsigned int index_reversed = sizeof(n) * 8 - 1;
	for(; index_reversed >= 0; index_reversed--) {
		reversed |= (n & 0x1u) << index_reversed;
		if(index_reversed == 0) return reversed;
		n >>= 1;
	}
}