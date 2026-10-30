#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
	if(argc != 2) {
		printf("Usage : ./canopen <filename>. Terminating...\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp; 
	if( (fp = fopen(argv[1], "r")) == NULL ) {
		printf("%s can't be opened. Terminating...\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("%s can be opened. Closing...\n", argv[1]); 
	fclose(fp); fp = NULL;
	printf("%s has been closed\n", argv[1]);
}

