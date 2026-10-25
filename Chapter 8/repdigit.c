#include<stdbool.h>
#include<stdio.h>

int main(void) {
	bool repeated[10] = {false};
	long n;
	int digit;

	printf("Enter a number : ");
	scanf("%lld", &n);

	while(n > 0) {
		digit = n%10;
		if(repeated[digit]) break;
		repeated[digit] = true;
		n /= 10;
	}

	if(n > 0) printf("Repeated digit\n");
	else printf("No repeated digit\n");
}