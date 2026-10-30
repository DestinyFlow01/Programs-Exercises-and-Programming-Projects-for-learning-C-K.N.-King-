#include<stdio.h>
#include<stdlib.h>

#define KEY ('&')

int main(int argc, char** argv) {
	if(argc != 3) {
		fprintf(stderr, "Usage : ./Prob5 input output. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	FILE *input, *output;
	if((input = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Input file %s can't be opened. Terminating...\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if((output = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Output file %s can't be opened. Terminating...\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	int original_ch, xor_ch;

	while((original_ch = getc(input)) != EOF) {
		xor_ch = original_ch ^ KEY;
		if(putc(xor_ch, output) == EOF) {
			fprintf(stderr, "Writing error to output file. Terminating...\n"); 
			fclose(input);
			fclose(output);
			exit(EXIT_FAILURE);
		}
		;
	}
	fclose(input);
	fclose(output);
}