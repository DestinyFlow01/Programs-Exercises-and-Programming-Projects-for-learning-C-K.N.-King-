#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MSG_LEN 100

int main() {
	printf("Enter a date (mm/dd/yyyy) : ");
	int month, day, year;
	scanf("%2d /%2d / %4d", &month, &day, &year);

	if(month > 12 || month < 1 || day > 31 || day < 0 || year < 0) exit(EXIT_FAILURE);

	char* month_name[] = {"January", "February", "March", "April", "May", "June", 
					"July", "August", "September", "October", "November", "December"};
	printf("You entered the date %s %d, %d\n", month_name[month-1], day, year);
}