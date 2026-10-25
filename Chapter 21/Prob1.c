#include<stdio.h>
#include<stddef.h>

struct s {
	char a; 
	int b[2];
	float c; 
};

#define PRINT(mem) printf("Offset of member "#mem" : %d\n", offsetof(struct s, mem))

int main(void) {
	PRINT(a);
	PRINT(b[0]);
	PRINT(b[1]);
	PRINT(c);
}