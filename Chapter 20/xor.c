#include<stdio.h>
#include<ctype.h>

#define KEY ('&')

int main(void) {
	int original_ch, xor_ch;

	while((original_ch = getchar()) != EOF) {
		xor_ch = original_ch ^ KEY;

		if(isprint(original_ch) && isprint(xor_ch)) putchar(xor_ch);
		else putchar(original_ch);
	}
}