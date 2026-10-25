#include<stdio.h>

int main(void) {
	int height = 8, length = 12, width = 10; 
	int volume = height * length * width;
	int weight = (volume + 165)/166;

	printf("Dimensions : %d x %d x %d\n", length, width, height);
	printf("Volume : %d\n", volume);
	printf("Dimensional weight (pounds) : %d\n", weight);
}