#include<stdio.h>

int main(void) {
	printf("How many numbers do you want to reverse? ");
	unsigned int n; scanf("%u", &n);
	int a[n];
	
	printf("Enter %d numbers : ", n);
	for(int i = 0; i<n; i++) scanf("%d", &a[i]);

	//Reversing order : 
	printf("In reverse order : ");
	for(int i = n-1; i>=0; i--) printf("%d ", a[i]);
	printf("\n");
}

/*
bool weekend[7] = {[0] = true, [6] = true};
*/