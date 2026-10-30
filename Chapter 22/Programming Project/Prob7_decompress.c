#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned char BYTE;

struct summary {
	BYTE occurence;
	BYTE value;
	BYTE first;
};

int main(int argc, char** argv) {
	if(argc != 2) {
		fprintf(stderr, "Usage : ./Prob7_decompress <compressed filename>. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	//Checking .rle extension : 
	if(strcmp(argv[1] + strlen(argv[1]) - 4, ".rle") != 0) {
		fprintf(stderr, "Compressed filename has no .rle extension. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp_input = fopen(argv[1], "rb");
	if(fp_input == NULL) {
		fprintf(stderr, "Input filename %s can't be opened. Terminating...\n", fp_input);
		exit(EXIT_FAILURE);
	}
	
	if(strlen(argv[1]) <= 4) {
		fprintf(stderr, "Input filename %s does not have .rle extension. Terminating...\n", fp_input);
		exit(EXIT_FAILURE);
	}

	char* filename_output = malloc(strlen(argv[1])+ 1);
	if(filename_output == NULL) {
		fprintf(stderr, "Output filename fails to malloc. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	strcpy(filename_output, argv[1]);
	filename_output[strlen(filename_output) - 4] = '\0';
	FILE* fp_output = fopen(filename_output, "wb");
	if(fp_output == NULL) {
		fprintf(stderr, "Output filename %s can't be opened. Terminating...\n", filename_output);
		exit(EXIT_FAILURE);
	}

	//Reading compress file and writing it into uncompressed file
	unsigned int ch1, ch2;	//ch1 as the number of occurence, ch2 as the value
	struct summary summary = {.first = 1, .occurence = 0, .value = 0};

	while(1) {
		if( fscanf(fp_input, "%2X", &ch1) != 1) break;
		if( fscanf(fp_input, "%2X", &ch2) != 1) break;
		summary.occurence = ch1; summary.value = ch2;
		for(int i = 0; i < summary.occurence; i++) fprintf(fp_output, "%c", summary.value);
		// printf("occurence = %X, value = %X\n", ch1, ch2);
	}

	fclose(fp_input);
	fclose(fp_output);
	free(filename_output);
}