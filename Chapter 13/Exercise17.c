#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_LEN 100

bool test_extension(const char*, const char*);
void get_extension(const char*, char*);
int read_line(char*, int);

int main(void) {
	char msg[MAX_LEN + 1];
	printf("File : "); read_line(msg, MAX_LEN);

	char extension[MAX_LEN];
	strcpy(extension, "TXT");	
	printf("Found = %s\n", test_extension(msg, extension) ? "1" : "0");
}

bool test_extension(const char* filename, const char* extension) {
	char extension_file[MAX_LEN+1];
	get_extension(filename, extension_file);

	//Converting extension to upper : 
	char extension_input[MAX_LEN+1];
	strcpy(extension_input, extension);
	int i;
	for(i = 0; i<strlen(extension_input); i++) extension_input[i] = toupper(extension[i]);
	extension_input[i] = '\0';

	int res = strcmp(extension_file, extension_input);
	return res == 0;
}

void get_extension(const char* file, char* extension) {
	int dot_loc = 0; 

	for(int i = strlen(file)-1; i >= 0; i--) {
		if(file[i] == '.') {
			dot_loc = i;
			if(file[dot_loc] == '.') strcpy(extension, &file[dot_loc+1]);
			else strcpy(extension, "");
			break;
		} 
	}

	int i;
	for(i = 0; i < strlen(extension); i++) extension[i] = toupper(extension[i]);
	extension[i] = '\0';
}

int read_line(char* msg, int max) {
	int ch, i = 0; 
	while((ch = getchar()) != '\n') {
		if(i < max) msg[i++] = ch;
	}
	msg[i] = '\0';
	return i;
}