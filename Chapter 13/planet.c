#include<stdio.h>
#include<string.h>

#define NUM_PLANET 9

int main(int argc, char* argv[]) {
	const char* planets[] = {
		"Mercury", "Venus", "Earth", "Mars",
		"Jupiter", "Saturn", "Uranus", "Neptunus", "Pluto"
	};

	for(char** p = &argv[1]; *p != NULL; p++) {
		int j;
		for(j = 0; j < NUM_PLANET; j++) {
			if(strcmp(planets[j], *p) == 0) {
				printf("%s is planet %d\n", *p, j+1);
				break;
			}
		}
		if(j == NUM_PLANET) printf("%s is not a planet\n", *p);
	}
}