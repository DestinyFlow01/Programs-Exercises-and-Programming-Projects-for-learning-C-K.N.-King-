#include<stdio.h>

int main(void) {
	int m, n;
	printf("Enter 2 integers : "); scanf("%d%d", &m, &n);

	//Swtich m and n so that m > n : 
	if(n > m) {
		int temp = n;
		n = m;
		m = temp;	
	}

	//Euclid algorithm :
	if(m == n) {
		printf("Greatest common divisor : %d\n", m);
		return 0;
	} 

	while(n != 0) {
		int t = m%n;
		m = n;
		n = t;
	}
	printf("Greatest common divisor : %d\n", m);
}