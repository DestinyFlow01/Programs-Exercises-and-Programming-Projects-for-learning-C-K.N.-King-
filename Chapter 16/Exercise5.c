#include<stdio.h>

struct date{
	int day, month, year;
};

int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Part a : 
int day_of_year(struct date d) {
	int day = d.day;
	for(int i = 0; i < d.month-1; i++) {
		day += month[i];
	}
	return day;
}

//Part b : 
int compare_dates(struct date d1, struct date d2) {
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