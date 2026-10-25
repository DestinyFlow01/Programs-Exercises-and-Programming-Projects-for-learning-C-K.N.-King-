#include<stdio.h>

int main(void) {
	int hour, minute; 
	printf("Enter a 24-hour time : "); scanf("%d:%d", &hour, &minute);
	printf("Equivalent 12-hour time : ");

	if(hour >= 0 && hour < 12) printf("%.2d:%.2d AM", hour, minute);
	else if(hour == 12) printf("12:00 PM");
	else if (hour > 12 && hour < 24) printf("%.2d:%.2d PM", hour-12, minute);

	printf("\n");
}