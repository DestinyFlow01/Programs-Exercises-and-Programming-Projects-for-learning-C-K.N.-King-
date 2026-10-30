#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 13

int main(void) {
	char name[MAX_LEN];
	int n = snprintf(name, MAX_LEN, "%s, %s", "Einstein", "Albert");

	if(n < 0) {
		fprintf(stderr, "Error in snprintf is detected. Terminating...\n");
		exit(EXIT_FAILURE);	
	}
	else {
		printf("name = %s, n = %d\n", name, n);
	}
}