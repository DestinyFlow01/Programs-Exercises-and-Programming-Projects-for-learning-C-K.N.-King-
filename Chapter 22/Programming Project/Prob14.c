#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 100

int main(void) {
	printf("Enter name of file to be encrypted : ");
	char input_name[MAX_NAME_LEN];
	scanf("%s", &input_name);

	

	int shift;
	printf("Enter shift amount (1-25) : "); scanf("%d", &shift);
	if(shift < 1 && shift > 25) {
		fprintf(stderr, "Shift must be between 1 and 25. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	char* output_name = malloc(strlen(input_name) + 1 + 4);
	if(output_name == NULL) {
		fprintf(stderr, "Malloc output filename fails. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	strcpy(output_name, input_name);
	strcat(output_name, ".enc");

	FILE* input_fp = fopen(input_name, "r");
	if(input_fp == NULL) {
		fprintf(stderr, "Filename %s can't be opened. Terminating...", input_name);
		free(output_name);
		exit(EXIT_FAILURE);
	}

	FILE* output_fp = fopen(output_name, "w");
	if(output_fp == NULL) {
		fprintf(stderr, "Filename %s can't be opened. Terminating...", output_name);
		free(output_name);
		exit(EXIT_FAILURE);
	}

	//Encryption : 
	int ch, encrypt_ch; 
	while((ch = getc(input_fp)) != EOF) fprintf(output_fp, "%c", ch + shift);
	
	free(output_name);
	fclose(input_fp);
	fclose(output_fp);
}