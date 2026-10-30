#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
	if(argc < 2) {
		fprintf(stderr, "Usage : ./Prob3 <filename 1> ... <filename n>. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp;
	for(int i = 1; i <= argc - 1; i++) {
		if( (fp = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "File %s can't be opened. Terminating...\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		int ch; 
		while((ch = getc(fp)) != EOF) putchar(ch);
		fclose(fp);
	}
	printf("\n");
}