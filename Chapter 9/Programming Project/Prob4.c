#include<stdio.h>

#define WORDS 100

void read_word(int repeated[26]) {
	char ch;
	unsigned int index = 0;
	while((ch = getchar()) != '\n') repeated[ch - 'a']++;
}

int equal_array(int repeated1[26], int repeated2[26]) {
	int i;
	for(i = 0; i<26; i++) {
		if(repeated1[i] != repeated2[i]) break;
	}
	return i;
}

int main(void) {
	unsigned int repeated1[26] = {0};
	unsigned int repeated2[26] = {0};
	
	printf("Enter first word : ");
	read_word(repeated1);
	printf("Enter second word : ");
	read_word(repeated2);

	int i = equal_array(repeated1, repeated2);
	if(i != 26) printf("The words are not anagram\n");
	else printf("The words are anagram\n");
}