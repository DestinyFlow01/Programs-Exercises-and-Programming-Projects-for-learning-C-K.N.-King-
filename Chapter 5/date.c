#include<stdio.h>

int main() {
	int month, year, day;
	printf("Enter date (mm/dd/yy) : "); scanf("%d/%d/%d", &month, &day, &year);

	//Outputting : 
	printf("Dated this %d", day);

	//Day : 
	switch(day % 10) {
		case 1 : printf("st"); break;
		case 2 : printf("nd"); break;
		case 3 : printf("rd"); break;
		default : printf("th");
	}
	printf(" day of ");

	//Month : 
	switch(month) {
		case 1 : printf("January, 20"); break;
		case 2 : printf("February, 20"); break;
		case 3 : printf("March, 20"); break;
		case 4 : printf("April, 20"); break;
		case 5 : printf("May, 20"); break;
		case 6 : printf("June, 20"); break;
		case 7 : printf("July, 20"); break;
		case 8 : printf("August, 20"); break;
		case 9 : printf("September, 20"); break;
		case 10 : printf("October, 20"); break;
		case 11 : printf("November, 20"); break;
		case 12 : printf("December, 20"); break;
	}

	//Year : 
	printf("%.2d\n", year);
}