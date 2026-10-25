#include<stdio.h>
#include<ctype.h>

int main(void) {
	int hour, minute; 
	char suffix;
	printf("Enter a 12-hour time : "); 
	scanf("%d : %d %c", &hour, &minute, &suffix);

	suffix = toupper(suffix);

	if(suffix == 'P' && hour != 12) hour += 12;
	printf("Equivalent 24-hour time : %d:%d\n", hour , minute);	

}