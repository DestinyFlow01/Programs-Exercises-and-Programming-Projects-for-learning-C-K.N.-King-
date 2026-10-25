#include<stdio.h>
#define PRINT(x) printf(#x " = %d\n", x)

int count_ones(unsigned char ch);

int main(void) {
	unsigned char ch = 222;
	printf("ch = %08b\n", ch);
	PRINT(count_ones(ch));
}

int count_ones(unsigned char ch) {
	int count = 0; 
	while(ch != 0) {
		count += (ch & 0x1);
		ch >>= 1;
	}
	return count;
}