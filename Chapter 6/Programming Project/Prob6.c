#include<stdio.h>

int main(void) {
	int n; 
	printf("Enter n : "); scanf("%d", &n);

	for(int d = 2; d*d <= n; d++) {
		if (d*d % 2 == 0) printf("%d\n", d*d);
	}
}