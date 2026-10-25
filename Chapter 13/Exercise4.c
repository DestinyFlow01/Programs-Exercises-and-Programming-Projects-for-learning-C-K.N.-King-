#include<stdio.h>
#include<ctype.h>

char read_line(char str[], int max_length) {
	int i = 0; 
	int ch; 

	while((ch = getchar()) != '\n') {
		if(i < max_length) str[i++] = ch;
	}
	return i;
}

// (a) Have it skip white space before beginning to store input characters
char read_line_a(char str[], int max_length) {
	int i = 0; 
	int ch; 

	while(isspace(getchar()));

	while((ch = getchar()) != '\n') {
		if(i < max_length) str[i++] = ch;
	}
	return i;
}

// (b) Have it stop reading at the first white-space character. Hint: To determine whether or
// not a character is white space, call the isspace function.
char read_line_b(char str[], int max_length) {
	int i = 0; 
	int ch; 

	while((ch = getchar()) != '\n' && !isspace(ch)) {
		if(i < max_length) str[i++] = ch;
	}
	return i;
}

// (c) Have it stop reading at the first new-line character, then store the new-line character in the string.
char read_line_c(char str[], int max_length) {
	int i = 0; 
	int ch; 

	while((ch = getchar()) != '\n') {
		if(i < max_length) str[i++] = ch;
	}
	if(i < max_length) str[i++] = '\n';
	return i;
}

// (d) Have it leave behind characters that it doesn’t have room to store.
char read_line_d(char str[], int max_length) {
	int i = 0; 
	int ch; 

	while((ch = getchar()) != '\n' && i < max_length) str[i++] = ch;
	return i;
}