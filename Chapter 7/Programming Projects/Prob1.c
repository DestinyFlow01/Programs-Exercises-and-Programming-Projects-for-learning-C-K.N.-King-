#include<stdio.h>

int main(void) {
	//For int : 
	int n_int, i;
	for(;;i++) if( (n_int = i * i) <= 0) break;

	printf("The square fails when i = %d with i*i = %d\n", i, i*i);
	printf("Previously, i = %d with i*i = %d\n\n", i-1, (i-1)*(i-1));

	//For short : 
	short n_short, s = 1;
	for(;;s++) if( (n_short = s * s) <= 0) break;

	printf("The square fails when s = %hd with s*s = %hd\n", s, s*s);
	printf("Previously, s = %hd with s*s = %hd\n\n", s-1, (s-1)*(s-1));

	//For long : 
	long n_long, l = 1;
	for(;;l++) if( (n_long = l * l) <= 0) break;

	printf("The square fails when l = %ld with l*l = %ld\n", l, l*l);
	printf("Previously, l = %ld with l*l = %ld\n", l-1, (l-1)*(l-1));
	
}