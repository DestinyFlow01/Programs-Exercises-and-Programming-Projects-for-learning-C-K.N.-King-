#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 100

void get_extension_1(const char*, char*);
void get_extension_2(const char*, char*);
int read_line(char*, int);

int main(void) {
	char msg[MAX_LEN + 1];
	printf("File : "); read_line(msg, MAX_LEN);

	char extension[MAX_LEN];
	get_extension_2(msg, extension);
	printf("Extension = %s\n", extension);
}

void get_extension_1(const char* file, char* extension) {
	int dot_loc = 0; 
	const char* p = file;

	while(*p != '\0') {
		if(*p == '.') dot_loc = p - file;
		p++;
	}

	if(file[dot_loc] == '.') strcpy(extension, &file[dot_loc+1]);
	else strcpy(extension, "");
}

void get_extension_2(const char* file, char* extension) {
	int dot_loc = 0; 

	for(int i = strlen(file)-1; i >= 0; i--) {
		if(file[i] == '.') dot_loc = i;
	}

	if(file[dot_loc] == '.') strcpy(extension, &file[dot_loc+1]);
	else strcpy(extension, "");
}

int read_line(char* msg, int max) {
	int ch, i = 0; 
	while((ch = getchar()) != '\n') {
		if(i < max) msg[i++] = ch;
	}
	msg[i] = '\0';
	return i;
}