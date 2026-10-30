#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_OCCURENCE 255

typedef unsigned char BYTE;

//Assuming that occurence value is at max 255
struct summary {
	BYTE occurence;
	BYTE value;
	BYTE first;
};

int main(int argc, char** argv) {
	if(argc != 2) {
		fprintf(stderr, "Usage : ./Prob7_compress <uncompress filename>. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp_input = fopen(argv[1], "rb");
	if(fp_input == NULL) {
		fprintf(stderr, "Input filename %s can't be opened. Terminating...\n", fp_input);
		exit(EXIT_FAILURE);
	}

	char* filename_output = malloc(strlen(argv[1]) + 5);
	if(filename_output == NULL) {
		fprintf(stderr, "Output filename fails to malloc. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	strcpy(filename_output, argv[1]);
	strcat(filename_output, ".rle");
	FILE* fp_output = fopen(filename_output, "wb");
	if(fp_output == NULL) {
		fprintf(stderr, "Output filename %s can't be opened. Terminating...\n", filename_output);
		exit(EXIT_FAILURE);
	}

	//Reading the input and writing into the output : 
	int ch;
	struct summary summary = {.occurence = 0, .value = 0, .first = 1}; 
	while((ch = getc(fp_input)) != EOF) {
		if(summary.value != ch || summary.occurence == MAX_OCCURENCE) {
			//Writing into output file first : 
			if(summary.first == 0) fprintf(fp_output, "%02X%02X", summary.occurence, summary.value);
			else summary.first = 0;

			//After encoding : 
			summary.value = ch; summary.occurence = 1;
		}	
		else summary.occurence++;
	}

	//Encoding the last one : 
	fprintf(fp_output, "%02X%02X", summary.occurence, summary.value);

	//Closing files : 
	fclose(fp_input);
	fclose(fp_output);
	free(filename_output);
}