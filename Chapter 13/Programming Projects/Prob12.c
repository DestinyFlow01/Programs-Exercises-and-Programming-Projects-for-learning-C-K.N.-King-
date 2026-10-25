#include<stdio.h>

#define WORDS 20
#define CHARS 30

void read_line(char*, int);

int main(void) {
	char sentence[WORDS+1][CHARS+1] = {'\0'};
	char stopping = '\0', ch;
	int words = 0, chars[WORDS] = {0};

	printf("Enter a sentence : ");
	while((ch = getchar()) != '\n') {
		if(ch == '.' || ch == '?' || ch == '!') {
			stopping = ch; break;
		}

		while(ch != ' ') {
			if(ch == '.' || ch == '?' || ch == '!') {
				stopping = ch; break;
			}
			sentence[words][(chars[words])++] = ch;
			if(chars[words] >= CHARS) break;
			ch = getchar();
		}
		words++;
		if(stopping != '\0') break;
	}

	printf("Reversal of sentence : ");
	for(int word = words-1; word >= 0; word--) {
		printf("%s", sentence[word]);
		if(word != 0) printf(" ");
	}
	putchar(stopping);
	printf("\n");
}

void read_line(char* str, int max) {
	int ch, i = 0; 
	while((ch = getchar()) != '\n' && ch != '.' && ch != '!' && ch != '?' && i < max) str[i++] = ch;
	str[i] = '\0';
}