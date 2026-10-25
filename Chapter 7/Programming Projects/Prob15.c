#include<stdio.h>

int main(void) {
	//Short : 
	short num_short = 1; 
	
	int i = 1;
	while(num_short >= 0) num_short *= (short)(i++);
	printf("Largest value of n (short) for factorial to be correct = %d with factorial = %hd\n", i, num_short);


	// Int : 
	int num_int = 1; 
	
	i = 1;
	while(num_int >= 0) num_int *= (i++);
	printf("Largest value of n (int) for factorial to be correct = %d with factorial = %d\n", i, num_int);

	// long : 
	long num_long = 1; 
	
	i = 1;
	while(num_long >= 0) num_long *= (long)(i++);
	printf("Largest value of n (long) for factorial to be correct = %d with factorial = %ld\n", i, num_long);

	// long : 
	long num_llong = 1; 
	
	i = 1;
	while(num_llong >= 0) num_llong *= (long long)(i++);
	printf("Largest value of n (long long) for factorial to be correct = %d with factorial = %lld\n", i, num_llong);
}