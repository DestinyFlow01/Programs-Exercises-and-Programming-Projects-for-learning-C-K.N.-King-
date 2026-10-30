#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int count_numchar(FILE* fp);
int count_numword(FILE* fp);
int count_numline(FILE* fp);

#define MAX_LEN 1000

int main(int argc, char** argv) {
	if(argc != 2) {
		fprintf(stderr, "Usage : ./Prob4 <filename>. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp; 
	if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Filename %s can't be opened. Terminating...\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Number of characters : %d\n", count_numchar(fp));
	printf("Number of words : %d\n", count_numword(fp));
	printf("Number of lines : %d\n", count_numline(fp));
}

int count_numchar(FILE* fp) {
	int count = 0, ch; 
	fseek(fp, 0, SEEK_SET);
	while((ch = getc(fp)) != EOF) count += (isprint(ch)) ? 1 : 0;
	return count;
}

int count_numword(FILE* fp) {
	int count = 0; 
	char ch[MAX_LEN];
	fseek(fp, 0, SEEK_SET); 
	while(fscanf(fp, " %s", ch) == 1) count++;
	return count;
}

int count_numline(FILE* fp) {
	int count = 1, ch; 
	fseek(fp, 0, SEEK_SET);
	while((ch = getc(fp)) != EOF) count += (ch == '\n') ? 1 : 0;
	return count;
}