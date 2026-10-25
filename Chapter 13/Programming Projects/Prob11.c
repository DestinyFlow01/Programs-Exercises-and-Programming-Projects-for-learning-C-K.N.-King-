#include<stdio.h>
#include<ctype.h>

#define SEN_LEN 1000

void read_line(char*, int);
double compute_average_word_length(const char*);

int main(void) {
	char sentence[SEN_LEN+1]; 
	printf("Enter a sentence : ");
	read_line(sentence, SEN_LEN);
	double average = (sentence[0] == '\0') ? -1 : compute_average_word_length(sentence);
	printf("Average word length : %.3lf\n", average);
}

void read_line(char* str, int max) {
	int ch, i = 0; 
	while((ch = getchar()) != '\n' && i < max) str[i++] = ch;
	str[i] = '\0';
}

double compute_average_word_length(const char* sentence) {
	double average = 0;
	int n = 1;  
	while(*sentence != '\0') {
		if(!isspace(*sentence)) average++;
		else n++;
		sentence++;
	}
	return (n == 0) ? -1 : average / n;
}