#include<stdio.h>
#include<ctype.h>
typedef unsigned char BYTE;

int main(void) {
	void* addr; 
	int num;

	printf("Address of main function : %p\n", &main);
	printf("Address of addr variable : %p\n\n", &addr);
	printf("Enter a (hex) address : "); scanf("%p", &addr);
	printf("Enter number of bytes to view : "); scanf("%d", &num);
	printf("\n");
	printf("    Address                   Bytes               Characters\n");
	printf(" --------------   -----------------------------   ----------\n");

	const BYTE* ptr = addr;
	for(; num > 0; num -= 10, ptr += 10) {
		printf("%p ", ptr);

		//Bytes :
		int i = 0; 
		for(; i < 10 && i < num; i++) printf("%2x ", ptr[i]);
		for(; i < 10; i++) printf("   ");

		//Chars : 
		printf(" ");
		for(i = 0; i < 10 && i < num; i++)
			putchar(isprint(ptr[i]) ? ptr[i] : '.');
		printf("\n");
	}
}