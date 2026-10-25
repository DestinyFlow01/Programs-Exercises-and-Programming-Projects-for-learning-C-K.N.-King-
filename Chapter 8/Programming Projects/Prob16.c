#include<stdio.h>

#define WORDS 100

int main(void) {
	char word1[WORDS];
	char word2[WORDS];
	unsigned int index1 = 0, index2 = 0;
	char ch;

	printf("Enter first word : ");
	unsigned int repeated1[26] = {0};
	while((ch = getchar()) != '\n') {
		word1[index1++] = ch;
		repeated1[ch - 'a']++;
	} 
	

	printf("Enter second word : ");
	unsigned int repeated2[26] = {0};
	while((ch = getchar()) != '\n') {
		word2[index2++] = ch;
		repeated2[ch - 'a']++;
	}

	int i;
	for(i = 0; i<26; i++) {
		if(repeated1[i] != repeated2[i]) break;
	}

	if(i != 26) printf("The words are not anagram");
	else printf("The words are anagram");
	printf("\n");
}