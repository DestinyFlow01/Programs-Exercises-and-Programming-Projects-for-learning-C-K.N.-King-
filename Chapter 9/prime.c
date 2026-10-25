#include<stdio.h>
#include<stdbool.h>

bool is_prime(int n) {
	if(n <= 1) return false; 

	for(int i = 2; i*i<n; i++) {
		if(n%i == 0) return false;
	}
	return true;
}


int main() {
	printf("Enter a number : "); 
	int n; scanf("%d", &n);

	if(is_prime(n)) printf("Is prime"); else printf("Not prime");
	printf("\n");
}