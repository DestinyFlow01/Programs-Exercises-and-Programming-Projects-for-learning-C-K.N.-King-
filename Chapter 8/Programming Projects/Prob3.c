#include<stdbool.h>
#include<stdio.h>

int main(void) {
	long n;
	int digit;
	
	printf("Enter a number : ");
	scanf("%lld", &n);

	while(n > 0) {
		unsigned int repeated[10] = {0};
		while(n > 0) {
			digit = n%10;
			repeated[digit]++;
			n /= 10;
		}

		printf("Repeated digit : ");
		for(int i = 0; i<10; i++) {
			if(repeated[i] > 1) printf("%d ", i);
		}
		printf("\n\n");
		printf("Enter a number : ");
		scanf("%lld", &n);
	}
	
}