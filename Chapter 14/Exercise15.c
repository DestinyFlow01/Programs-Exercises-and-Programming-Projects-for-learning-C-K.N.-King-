#include<stdio.h>

// #define ENGLISH "Insert Disk 1"
// #define FRENCH "Inserez Le Disque 1"
#define SPANISH "Inserte EL Disco 1"

int main(void) {
	#ifdef ENGLISH
		char* str = ENGLISH;
	#elif defined FRENCH
		char* str = FRENCH;
	#elif defined SPANISH
		char* str = SPANISH;
	#endif
	printf("str = %s\n", str);
}