#include<stdio.h>
#include<ctype.h>

#define SENTENCE 100
int compute_vowel_count(const char*);

int main(void) {
	char ch; 
	printf("Enter a sentence : ");
	
	char sentence[SENTENCE];
	int i = 0;
	while( (ch = getchar()) != '\n') sentence[i++] = ch;
	int sum = compute_vowel_count(sentence);
	printf("Your sentence contains %d vowels\n", sum);
}

int compute_vowel_count(const char* sentence) {
	int sum = 0;
	while(*sentence != '\0') {
		switch(tolower(*sentence)) {
			case 'a' : case 'e' : case 'o' : case 'i' : case 'u' : sum++; break;
		}
		sentence++;
	}
	return sum;
}