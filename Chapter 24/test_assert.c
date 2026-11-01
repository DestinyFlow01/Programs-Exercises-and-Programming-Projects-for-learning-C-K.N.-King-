#include<stdio.h>
#include<assert.h>

#define OFF_BY_ONE

int main(void) {
	int a[10];

	#ifdef OFF_BY_ONE
		for(int i = 0; i<=10; i++)
	#else
		for(int i = 0; i<10; i++)
	#endif
	 {
		assert(0 <= i && i < 10); 
		a[i] = 0;
	}
	printf("Initialization to 0 done.\n");
}