#include<stdio.h>

#define ERROR(msg, idx) fprintf(stderr, (msg), (idx))

int main(void) {
	int index = 1;
	ERROR("Range error : index = %d\n", index);
}