#include<stdio.h>
#include<stdlib.h>

void reduce(int, int, int*, int*);

int main(void) {
	int num, denom, red_num, red_denom; 

	printf("Enter a fraction : "); scanf("%d/%d", &num, &denom);
	if(denom == 0) {
		printf("Denominator must be nonzero\n");
		exit(EXIT_FAILURE);
	}

	reduce(num, denom, &red_num, &red_denom);
	
	
	if (red_denom == 1) printf("In lowest term : %d\n", red_num);
	else printf("In lowest term : %d/%d\n", red_num, red_denom);
	
}

void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator) {
	//Finding gcd : 
	int gcd = 1;
	int m,n;
	
	//Swtich m and n so that m > n : 
	if(numerator > denominator) {
		n = denominator; m = numerator;	
	}
	else {
		m = denominator; n = numerator;
	}

	//Euclid algorithm :
	if(m != n) {
		while(n != 0) {
			int t = m%n;
			m = n;
			n = t;
		}	
	} 
	gcd = m;
	*reduced_numerator = numerator/gcd, *reduced_denominator = denominator/gcd;
}