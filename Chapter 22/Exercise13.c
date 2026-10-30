#include<stdio.h>
#include<stdlib.h>

int line_length(const char*, int);

int main(void) {
	printf("Length = %d\n", line_length("sample.txt", 5));
}

int line_length(const char *filename, int n) {
	FILE* fp = fopen(filename, "r");

	if(fp == NULL) {
		fprintf(stderr, "Opening file %s fails. Terminating...\n", filename);
		exit(EXIT_FAILURE);
	}

	//First, we need to find the nth line : 
	if(n <= 0) {
		fclose(fp);
		return 0;
	} 
	int ch; 
	for(int i = 1; i<n; i++) {
		while((ch = getc(fp)) != '\n' && ch != EOF);
		if(ch == EOF) {
			fclose(fp);
			return 0;
		} 
	}

	//We are now in nth line. 
	int length = 0; 
	while((ch = getc(fp)) != '\n' && ch != EOF) length++;
	fclose(fp);
	return length;
}