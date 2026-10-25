#include<stdio.h>
#define SCALE_PI (4.0f / 3.0f * 3.14159265f)

int main(void) {
	float radius = 10.0f;
	float volume = SCALE_PI * radius * radius * radius;

	printf("Radius = %.2f\n", radius);
	printf("Volume = %.2f\n", volume);
}