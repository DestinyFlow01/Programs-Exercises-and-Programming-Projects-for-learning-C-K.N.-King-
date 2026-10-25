#include<stdio.h>
#include<stdlib.h>

void split_time(long, int*, int*, int*);

int main(void) {
	long total_sec; 
	printf("Total sec = "); scanf("%Ld", &total_sec);
	if(total_sec < 0) {
		printf("Total sec must not negative. Terminating..."); 
		exit(EXIT_FAILURE);
	} 
	int hr, min, sec;
	split_time(total_sec, &hr, &min, &sec);
	printf("Hour = %d, Minute = %d, Second = %d\n", hr, min, sec);
}

void split_time(long total_sec, int* hr, int* min, int* sec) {
	*hr = *min = *sec = 0;

	long time = total_sec;
	*hr = time / 3600; time %= 3600;
	*min = time / 60; *sec = time % 60;
}