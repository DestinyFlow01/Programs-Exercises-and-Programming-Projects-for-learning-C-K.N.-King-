#include<stdio.h>
#define INCHES_PER_POUND 166

int main() {
	int length, width, height; 
	printf("Enter height of the box : "); scanf("%d", &height);
	printf("Enter length of the box : "); scanf("%d", &length);
	printf("Enter width of the box : "); scanf("%d", &width);

	int volume = length * height * width;
	int weight = (volume + INCHES_PER_POUND - 1)/INCHES_PER_POUND;
	printf("Dimensions : %d x %d x %d\n", length, width, height);
	printf("Volume : %d\n", volume);
	printf("Dimensional weight (pounds) : %d\n", weight);
}