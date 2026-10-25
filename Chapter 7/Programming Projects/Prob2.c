#include<stdio.h>

int main(void) {
	int n; 
	printf("This program prints a table of squares.\nEnter number of entries in table: ");
	scanf("%d", &n);

	//Clear buffer : 
	char c;
	while( (c = getchar()) != '\n' && (c = getchar()) != EOF);

	for(int i = 1; i <= n; i++) {
		printf("%10d%10d\n", i, i*i);
		
		if(i%24 == 0) {
			printf("Press Enter to continue ... ");
			while(getchar() != '\n');
		}
	} 
}