#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int count_numchar(FILE* fp) {
	int count = 0, ch; 
	fseek(fp, 0L, SEEK_SET);
	while((ch = getc(fp)) != EOF) count++;
	fseek(fp, 0L, SEEK_SET); //return to the beginning of the file
	return count;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		fprintf(stderr, "Usage : ./Prob6 <filename>. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp;
	if((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Filename %s can't be opened. Terminating...\n", argv[1]); 
		exit(EXIT_FAILURE);
	}

	//Keeping the data during byte to be accessed later in characters
	int stack[10];
	int ch, top = 0; 
	int num_char = count_numchar(fp);
	int num_offset = ( (num_char - num_char/10 * 10) == 0) ? num_char/10 : (num_char/10 + 1) ;

	printf("num char = %d, num offset = %d\n", num_char, num_offset);
	puts("Offset             Byte              Characters");
	puts("------ ----------------------------- ----------");
	
	fseek(fp, 0, SEEK_SET);
	for(int i = 0; i < num_offset; i++) {
		//Printing offset : 
		printf("%6d ", i*10);

		//Printing bytes :
		for(top = 0; top < 10; top++) {
			if((ch = getc(fp)) == EOF) break;
			stack[top] = (isprint(ch) ? ch : '.');
			printf("%02X ", ch);
		}
		for(int i = top; i < 10; i++) {
			printf("   ");
			stack[i] = ' ';
		} 

		//Characters : Assuming that stack has been filled with top as the one not filled yet
		for(int i = 0; i<top; i++) printf("%c", stack[i]);
		printf("\n");
	}
	fclose(fp);
}