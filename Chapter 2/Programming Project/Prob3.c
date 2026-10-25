#include<stdio.h>
#define SCALE_PI (4.0f / 3.0f * 3.14159265f)

int main(void) {
	float radius;
	printf("Radius = "); scanf("%f", &radius);
	float volume = SCALE_PI * radius * radius * radius;
	printf("Volume = %.2f\n", volume);
}