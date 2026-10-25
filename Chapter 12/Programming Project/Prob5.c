#include<stdio.h>

#define WORDS 1000
#define CHARS 1000

int main(void) {
	char sentence[WORDS][CHARS] = {'\0'};
	char stopping = '\0', ch, *ptr_sentence = sentence[0];
	int words = 0;

	printf("Enter a sentence : ");
	while(1) {
		ch = getchar();
		if(ch == '.' || ch == '?' || ch == '!') {
			stopping = ch; break;
		}

		while(ch != ' ') {
			if(ch == '.' || ch == '?' || ch == '!') {
				stopping = ch; break;
			}
			*ptr_sentence++ = ch;
			ch = getchar();
		}
		words++;
		ptr_sentence = sentence[words];
		if(stopping != '\0') break;
	}

	printf("Reversal of sentence : ");
	ptr_sentence = sentence[words-1];
	while(!(words == 0 && *ptr_sentence == '\0')) {
		if(*ptr_sentence == '\0') {
			ptr_sentence = sentence[--words];
			printf(" ");
		}
		putchar(*ptr_sentence++);
	}
	putchar(stopping);
	printf("\n");
}