#include<stdio.h>

#define WORDS 1000
#define CHARS 1000

int main(void) {
	char sentence[WORDS][CHARS] = {'\0'};
	char stopping = '\0', ch;
	int words = 0, chars[WORDS] = {0};

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
			sentence[words][(chars[words])++] = ch;
			ch = getchar();
		}
		words++;
		if(stopping != '\0') break;
	}

	printf("Reversal of sentence : ");
	for(int word = words-1; word >= 0; word--) {
		for(int chr = 0; chr < chars[word]; chr++) {
			putchar(sentence[word][chr]);
		}
		if(word != 0) printf(" ");
	}
	putchar(stopping);
	printf("\n");
}