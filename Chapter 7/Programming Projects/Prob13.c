#include<stdio.h>

int main(void) {
	int sum = 0, n = 0;
	double average; 
	char ch = ' ';
	
	printf("Enter a sentence : ");
	
	do {
		//Start from new word : 
		sum = 0;
		// printf("n = %d\n", n);

		while((ch = getchar()) != ' ' && ch != '\n') sum++;
		n++;
		average += sum;

		if(ch == '\n') break;
	} while(1);
	

	if(n == 0) return -1;
	
	average /= n;
	printf("Average word length : %.1lf\n", average);
}