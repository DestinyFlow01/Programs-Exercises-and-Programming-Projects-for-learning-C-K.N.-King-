#include<stdio.h>

unsigned short swap_bytes(unsigned short i);

int main(void) {
	printf("Enter a hexadecimal number (up to 4 digits) : ");
	unsigned short num; scanf("%hx", &num);
	printf("Swapped %hx = %hx\n", num, swap_bytes(num));
}

unsigned short swap_bytes(unsigned short i) {
	return ((i & 0xFF) << 8 | ((i >> 8) & 0xFF));
}