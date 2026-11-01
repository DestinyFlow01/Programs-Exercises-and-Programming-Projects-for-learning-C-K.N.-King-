#include<stdio.h>
#include<setjmp.h>

jmp_buf env;

void f(void) {
	longjmp(env, 1);
}

int main(void) {
	int i = 2; i++;

	if(setjmp(env) == 0) {
		i = 99; 
		f();
	}
	else {
		printf("i = %d\n", i);
	}
}