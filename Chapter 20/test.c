#include<stdio.h>
#include<stddef.h>
#define PRINT(x) printf(#x " = %d\n", x)
typedef unsigned char BYTE;
typedef unsigned short WORD;

struct baseline {
	unsigned char x : 3;
	unsigned char y : 5;
};

struct a {
	unsigned x : 3;
	unsigned y : 5;
};

struct b {
	unsigned x : 3;
	unsigned : 5;
	unsigned y : 5;
};

struct c {
	unsigned x : 3; 
	unsigned : 0;
	unsigned y : 5;
};

struct a_char {
	unsigned char x : 3;
	unsigned char : 1;
	unsigned char y : 5;
};

struct b_char {
	unsigned char x : 3; 
	unsigned char : 0;
	unsigned char y : 5;
};

struct a_double {
	unsigned char x : 3; 
	unsigned char : 1;
	unsigned char y : 5; 
	double tst;	//8 bytes
};

struct b_double {
	unsigned char x : 3; 
	unsigned char : 0;
	unsigned char y : 5; 
	double tst;	//8 bytes
};

union {
	struct {
		WORD ax, bx, cx, dx;
	} words;
	struct {
		BYTE al, ah, bl, bh, cl, ch, dl, dh;
	} bytes;
} regs;

struct float_bits {
	unsigned sign : 1;
	unsigned exponent : 8;
	unsigned fraction : 23;
};

int main(void) {
	// PRINT(sizeof(struct baseline));
	// PRINT(sizeof(struct a));
	// PRINT(sizeof(struct b));
	// PRINT(sizeof(struct c));
	// PRINT(sizeof(struct a_char));
	// PRINT(sizeof(struct b_char));
	// PRINT(sizeof(struct a_double));
	// PRINT(sizeof(struct b_double));

	regs.words.ax = 0x1234;
	printf("al = %hx, ah = %hx\n", regs.bytes.al, regs.bytes.ah); //al = 34, ah = 12 (little endian)
	PRINT(&regs.bytes.al);
	PRINT(&regs.bytes.ah);
	PRINT(&regs.words.ax);
	PRINT(&regs.bytes.bl);
	PRINT(&regs.bytes.bh);
	PRINT(&regs.words.bx);


	unsigned x = 1;
	printf("%s\n", *(unsigned char *)&x ? "little" : "big");

	PRINT(sizeof(struct float_bits));
}