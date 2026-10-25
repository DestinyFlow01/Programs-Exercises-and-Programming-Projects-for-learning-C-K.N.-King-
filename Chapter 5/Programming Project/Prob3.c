#include<stdio.h>

int main(void) {
	/*
	Transaction size Commission rate
	Under $2,500 $30 + 1.7%
	$2,500–$6,250 $56 + 0.66%
	$6,250–$20,000 $76 + 0.34%
	$20,000–$50,000 $100 + 0.22%
	$50,000–$500,000 $155 + 0.11%
	Over $500,000 $255 + 0.09%
	*/

	float num_share, price, commission1, commission2; 

	printf("Enter the number of share: "); scanf("%f", &num_share);
	printf("Enter the price per share : "); scanf("%f", &price);

	float trade = num_share * price;

	if(trade < 2500) commission1 = 30 + 1.7 * trade/100;
	else if (trade < 6250) commission1 = 56 + 0.66 * trade/100;
	else if (trade < 20000) commission1 = 76 + 0.34 * trade/100;
	else if (trade < 50000) commission1 = 100 + 0.22 * trade/100;
	else if (trade < 500000) commission1 = 155 + 0.11 * trade/100;
	else commission1 = 255 + 0.09 * trade/100;

	if(commission1 < 39) commission1 = 39; 

	printf("Commission by broker 1: $%.2f\n", commission1);

	commission2 = (num_share < 2000) ? (33 + 3*0.01*num_share) : (33 + 2*num_share * 0.01);

	printf("Commission by broker 2: $%.2f\n", commission2);
}