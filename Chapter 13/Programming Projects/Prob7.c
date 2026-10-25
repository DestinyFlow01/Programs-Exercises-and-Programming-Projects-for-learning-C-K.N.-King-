#include<stdio.h>

int main(void) {
	int num;
	printf("Enter a two-digit number : "); scanf("%2d", &num);
	printf("You entered the number ");
	int tens = num/10, ones = num%10;
	char* tens_str[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	char* ones_str[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	if(tens == 1) { 
		switch (ones) {
			case 0 : printf("ten"); break;
			case 1 : printf("eleven"); break;
			case 2 : printf("twelve"); break;
			case 3 : printf("thirteen"); break;
			case 4 : printf("fourteen"); break;
			case 5 : printf("fifteen"); break;
			case 6 : printf("sixteen"); break;
			case 7 : printf("seventeen"); break;
			case 8 : printf("eighteen"); break;
			case 9 : printf("nineteen"); break;
		}
	}
	else {
		if(tens > 1) printf("%s", tens_str[tens - 2]);
		if(tens != 0 && ones != 0) printf("-");
		if(ones > 0) printf("%s", ones_str[ones - 1]);
	}
	printf("\n");
	
}