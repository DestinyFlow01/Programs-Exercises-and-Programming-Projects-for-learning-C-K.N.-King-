#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define NUM_PLANET 9

int caseinsensitive_strcmp(const char*, const char*);

int main(int argc, char* argv[]) {
	const char* planets[] = {
		"Mercury", "Venus", "Earth", "Mars",
		"Jupiter", "Saturn", "Uranus", "Neptunus", "Pluto"
	};

	for(char** p = &argv[1]; *p != NULL; p++) {
		int j;
		for(j = 0; j < NUM_PLANET; j++) {
			if(caseinsensitive_strcmp(planets[j], *p) == 0) {
				printf("%s is planet %d\n", *p, j+1);
				break;
			}
		}
		if(j == NUM_PLANET) printf("%s is not a planet\n", *p);
	}
}

int caseinsensitive_strcmp(const char* s1, const char* s2) {
	if(strlen(s1) != strlen(s2)) return -1;

	while(*s1 && tolower(*(s1)) == tolower(*(s2))) {s1++; s2++;}
	// printf("diff = %d\n", tolower(*s1) - tolower(*s2));
	return tolower(*s1) - tolower(*s2);
}