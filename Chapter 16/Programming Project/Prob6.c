#include<stdio.h>

struct Date {
	int day;
	int month; 
	int year;
};

int compare_dates(struct Date d1, struct Date d2) {
	if(d1.year < d2.year) return -1;
	else if (d1.year > d2.year) return 1;
	else {
		if(d1.month < d2.month) return -1;
		else if (d1.month > d2.month) return 1;
		else {
			if(d1.day < d2.day) return -1;
			else if (d1.day > d2.day) return 1;
			else return 0;
		}
	}
}

int main(void) {	
	struct Date date1, date2;
	printf("Enter first date (mm/dd/yy) : "); scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year);
	printf("Enter second date (mm/dd/yy) : "); scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);
	int found = compare_dates(date1, date2);
	if(found == 0) printf("The dates are the same\n");
	else if (found == -1) printf("date 1 is earlier than d2\n");
	else if (found == 1) printf("date 1 is later than d2\n");
}