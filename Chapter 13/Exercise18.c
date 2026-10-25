#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_LEN 1000

void remove_filename(char*);
void read_line(char*, int);

int main(void) {
	char url[MAX_LEN+1];
	printf("URL : "); read_line(url, MAX_LEN);

	remove_filename(url);
	printf("Modified URL : %s\n", url);
}

void remove_filename(char* url) {
	for(int i = strlen(url) - 1; i >= 0; i--) {
		if(url[i] == '/') {
			url[i] = '\0';
			break;
		}
	}
}

void read_line(char* str, int max) {
	int ch, i = 0;
	while( (ch = getchar()) != '\n' && i < max) str[i++] = ch;
	str[i] = '\0';
}