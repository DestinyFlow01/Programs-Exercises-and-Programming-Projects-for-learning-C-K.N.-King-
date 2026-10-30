#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
    if(argc == 1) {
        printf("Usage : ./canopen <filename 1> ... <filename n>. Terminating...\n");
        exit(EXIT_FAILURE);
    }

    int i = argc - 1;
    while(i >= 1) {
        FILE* fp;
        if( (fp = fopen(argv[i], "r")) == NULL ) {
            fprintf(stderr, "File %s can't be opened. Terminating...\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        printf("File %s can be opened\n", argv[i--]);
    }
}