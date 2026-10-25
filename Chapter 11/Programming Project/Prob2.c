#include<stdio.h>
#include<stdlib.h>

#define TIME1 (8*60)
#define TIME2 (9*60 + 43)
#define TIME3 (11*60 + 19)
#define TIME4 (12*60 + 47)
#define TIME5 (14*60)
#define TIME6 (15*60+45)
#define TIME7 (19*60)
#define TIME8 (21*60+45)

void find_closest_flight(int, int*, int*);

int main(void) {
	int hour, minute; 
	printf("Enter a 24-hour time : "); scanf("%d:%d", &hour, &minute);
	if(hour < 1 || minute < 0 || minute > 59) {
		printf("Hour must be positive and minute must be between 0 and 59. Terminating...");
		exit(EXIT_FAILURE);
	}

	int overall_minute = hour*60 + minute;
	int min_dep = TIME1, min_arr = 10*60 + 16;
	find_closest_flight(overall_minute, &min_dep, &min_arr);

	printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", min_dep/60, min_dep%60, min_arr/60, min_arr%60);
}

void find_closest_flight(int desired_time, int* departure_time, int* arrival_time) {
	int time_diff = (desired_time > TIME1) ? (desired_time - TIME1) : TIME1 - desired_time;
	int min_arrhour, min_arrmin;

	int time = (desired_time > TIME2) ? (desired_time - TIME2) : TIME2 - desired_time;
	if(time_diff > time) {
		time_diff = time;
		*departure_time = TIME2;
		min_arrhour = 11; 
		min_arrmin = 52;
	}

	time = (desired_time > TIME3) ? (desired_time - TIME3) : TIME3 - desired_time;
	if(time_diff > time) {
		time_diff = time;
		*departure_time = TIME3;
		min_arrhour = 13; 
		min_arrmin = 31;
	}
	

	time = (desired_time > TIME4) ? (desired_time - TIME4) : TIME4 - desired_time;
	if(time_diff > time) {
		time_diff = time;
		*departure_time = TIME4;
		min_arrhour = 15; 
		min_arrmin = 0;
	}

	time = (desired_time > TIME5) ? (desired_time - TIME5) : TIME5 - desired_time;
	if(time_diff > time) {
		time_diff = time;
		*departure_time = TIME5;
		min_arrhour = 16; 
		min_arrmin = 8;
	}

	time = (desired_time > TIME6) ? (desired_time - TIME6) : TIME6 - desired_time;
	if(time_diff> time) {
		time_diff = time;
		*departure_time = TIME6;
		min_arrhour = 17; 
		min_arrmin = 55;
	}

	time = (desired_time > TIME7) ? (desired_time - TIME7) : TIME7 - desired_time;
	if(time_diff > time) {
		time_diff = time;
		*departure_time = TIME7;
		min_arrhour = 21; 
		min_arrmin = 20;
	}

	time = (desired_time > TIME8) ? (desired_time - TIME8) : TIME8 - desired_time;
	if(time_diff > time) {
		time_diff = time;
		*departure_time = TIME8;
		min_arrhour = 23; 
		min_arrmin = 58;
	}
	*arrival_time = min_arrhour*60 + min_arrmin;
}