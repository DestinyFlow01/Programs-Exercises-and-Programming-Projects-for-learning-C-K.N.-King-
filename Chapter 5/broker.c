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

	float trade, commission; 

	printf("Enter value of trade: "); scanf("%f", &trade);

	if(trade < 2500) commission = 30 + 1.7 * trade/100;
	else if (trade < 6250) commission = 56 + 0.66 * trade/100;
	else if (trade < 20000) commission = 76 + 0.34 * trade/100;
	else if (trade < 50000) commission = 100 + 0.22 * trade/100;
	else if (trade < 500000) commission = 155 + 0.11 * trade/100;
	else commission = 255 + 0.09 * trade/100;

	if(commission < 39) commission = 39; 

	printf("Commission: $%.2f\n", commission);
}