#include<stdlib.h>
#include<stdio.h>

void* my_malloc(int num_bytes) {
	void* mem = malloc(num_bytes);
	if(mem == NULL) {
		printf("Malloc error. Terminating...\n");
		exit(EXIT_FAILURE);
	}
	return mem;
}