#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Usage : ./fcopy <source> <destination>. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	FILE *source_fp, *dest_fp;
	if((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Source file %s can't be opened. Terminating...\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Destination file %s can't be opened. Terminating...\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	int ch;
	while( (ch = getc(source_fp)) != EOF) putc(ch, dest_fp);

	fclose(source_fp);
	fclose(dest_fp);
}