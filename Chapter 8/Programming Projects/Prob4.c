#include<stdio.h>
#define N 10

int main(void) {
	int a[N];
	
	printf("Enter 10 numbers : ");
	for(size_t i = 0; i<sizeof(a) / sizeof(a[0]); i++) scanf("%d", &a[i]);

	//Reversing order : 
	printf("In reverse order : ");
	for(size_t i = sizeof(a) / sizeof(a[0])-1; i>=0; i--) {
		printf("%d ", a[i]);
		if(i == 0) break;
	} 
	printf("\n");
}