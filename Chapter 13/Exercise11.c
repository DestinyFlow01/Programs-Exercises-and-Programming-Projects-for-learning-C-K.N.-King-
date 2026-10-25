#include<stdio.h>
#include<string.h>

int strcmp(char *s, char *t) {
	int i;
	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0') return 0;
	return s[i] - t[i];
}

int strcmp_new(char *s, char *t) {
	while(*s == *t) {
		if(*(s++) == '\0') return 0;
		t++;
	}
	return *s - *t;
}