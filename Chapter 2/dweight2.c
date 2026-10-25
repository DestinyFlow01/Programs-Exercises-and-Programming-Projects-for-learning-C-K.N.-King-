#include<stdio.h>

int main(void) {
	int height, length, width;
	
	printf("Enter height of the box : "); scanf("%d", &height);
	printf("Enter length of the box : "); scanf("%d", &length);
	printf("Enter width of the box : "); scanf("%d", &width);

	int volume = height * length * width;
	int weight = (volume + 165)/166;

	printf("Dimensions : %d x %d x %d\n", length, width, height);
	printf("Volume : %d\n", volume);
	printf("Dimensional weight (pounds) : %d\n", weight);
}