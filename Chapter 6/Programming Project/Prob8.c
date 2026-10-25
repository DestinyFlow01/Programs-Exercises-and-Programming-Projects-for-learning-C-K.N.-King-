#include<stdio.h>

int main(void) {
	int num_days, start_day; 
	printf("Enter number of days in month: "); scanf("%d", &num_days);
	printf("Enter starting day of the week (1=Sun, 7=Sat): "); scanf("%d", &start_day);
	if(start_day <= 0) start_day = 1; 
	else if (start_day > 7) start_day = 7;

	//Sun Mon Tue Wed Thu Fri Sat
	int buf = 1;
	for(int i = 1; i<start_day; i++, buf++) printf("\t");

	for(int i = 1; i<=num_days; i++) {
		if(buf%8 == 0) {
			buf = 1; printf("\n");
		} 
		printf("%d\t", i);
		buf++;
	}
	printf("\n");
}