#include<stdio.h>

#define STR(x) #x 
#define XSTR(x) STR(x)
#define LINE_FILE "Line " XSTR(__LINE__) " of file " XSTR(__FILE__)

int main(void) {
	#line 10 "foo.c"
	const char *str = LINE_FILE;
	printf("str = %s\n", str);
}