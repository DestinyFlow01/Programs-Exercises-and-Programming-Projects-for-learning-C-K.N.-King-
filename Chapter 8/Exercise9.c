#include<stdio.h>

#define DAY 30
#define HOUR 24

int main(void) {
	double temperature_reading[DAY][HOUR] = {0};

	//After filling, we calculate the average : 
	double sum = 0; 
	for(int i = 0; i<DAY; i++) {
		for(int j = 0; j<HOUR; j++) sum += temperature_reading[i][j];
	}
	double average = sum/(DAY*HOUR);
}