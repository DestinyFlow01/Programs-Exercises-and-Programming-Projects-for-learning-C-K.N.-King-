#include<stdio.h>

int main(void) {
	int num;
	printf("Enter item number: "); scanf("%d", &num);

	float price;
	printf("Enter unit price: "); scanf("%f", &price);

	int month, date, year; 
	printf("Enter purchase date (mm/dd/yyyy) : "); scanf("%d/%d/%d", &month, &date, &year);

	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
	printf("%-d\t\t$ %7.2f\t%-.2d/%-.2d/%-.4d\n\n", num, price, month, date, year);
}