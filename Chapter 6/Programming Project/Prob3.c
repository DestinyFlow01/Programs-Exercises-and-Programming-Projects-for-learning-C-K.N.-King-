#include<stdio.h>

int main(void) {
	int a, b, m, n; 

	printf("Enter a fraction : "); scanf("%d/%d", &a, &b);

	//Finding gcd : 
	int gcd = 1;
	
	//Swtich m and n so that m > n : 
	if(a > b) {
		n = b; m = a;	
	}
	else {
		m = b; n = a;
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

	a /= gcd, b /= gcd;

	printf("In lowest term : %d/%d\n", a, b);
	
}