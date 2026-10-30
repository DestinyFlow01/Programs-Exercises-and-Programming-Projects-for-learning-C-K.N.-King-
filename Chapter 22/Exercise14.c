#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 100
#define TO_STR(x) #x
#define STR(x) TO_STR(x)

/// @brief Problem 14a your own version of fgets
/// @param s pointer to char for which the message is to be stored
/// @param n number of character to be stored
/// @param stream source input stream
/// @return null pointer if a read error occurs or they reach the end of input 
/// stream. Otherwise it returns the first argument
char* my_fgets(char* restrict s, int n, FILE* restrict stream) {
	if (n <= 0) return NULL;

	int i = 0, ch;
	while(i < n-1 && (ch = getc(stream))) {
		s[i++] = (char)ch;
		if(ch == '\n') break;
	}

	if(i == 0) return NULL;
	s[i] = '\0';
	return s;
}

/// @brief Problem 14b your own version of fputs
/// @param s message in form of string to be outputted
/// @param stream destination output stream
/// @return EOF if write error occurs; otherwise a nonnegative number
int my_fputs(const char* restrict s, FILE* restrict stream) {
	return (fprintf(stream, "%s", s) < 0) ? EOF : 1;
}