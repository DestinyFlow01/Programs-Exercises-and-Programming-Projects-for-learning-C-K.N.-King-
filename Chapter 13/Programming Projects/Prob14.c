#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define WORDS 100
bool are_anagrams(const char*, const char*);

int main(void) {
	char word1[WORDS];
	char word2[WORDS];
	unsigned int index1 = 0, index2 = 0;
	char ch;

	printf("Enter first word : ");
	while((ch = getchar()) != '\n') word1[index1++] = ch;
	word1[index1] = '\0';

	printf("Enter second word : ");
	while((ch = getchar()) != '\n') word2[index2++] = ch;
	word2[index2] = '\0';

	printf("Anagram : %s\n", are_anagrams(word1, word2) ? "True" : "False");

}

bool are_anagrams(const char *word1, const char *word2) {
	int repeated1[26] = {0}, repeated2[26] = {0};
	
	for(const char* ptr = word1; *ptr != '\0'; ptr++) repeated1[*ptr - 'a']++;
	for(const char* ptr = word2; *ptr != '\0'; ptr++) repeated2[*ptr - 'a']++;
	int i;
	for(i = 0; i<26; i++) {
		if(repeated1[i] != repeated2[i]) break;
	}
	return i == 26;
}