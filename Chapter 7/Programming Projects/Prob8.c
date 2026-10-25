#include<stdio.h>
#include<ctype.h>

#define TIME1 (8*60)
#define TIME2 (9*60 + 43)
#define TIME3 (11*60 + 19)
#define TIME4 (12*60 + 47)
#define TIME5 (14*60)
#define TIME6 (15*60+45)
#define TIME7 (19*60)
#define TIME8 (21*60+45)

int main(void) {
	int hour, minute; 
	char suffix;
	printf("Enter a 12-hour time : "); 
	scanf("%d : %d %c", &hour, &minute, &suffix);

	suffix = toupper(suffix);

	if(suffix == 'P' && hour != 12) hour += 12;
	

	int overall_minute = hour*60 + minute;
	int min_arrhour = 10, min_arrmin = 16, min_time = TIME1;
	int time_diff = (overall_minute > TIME1) ? (overall_minute - TIME1) : TIME1 - overall_minute;

	int time = (overall_minute > TIME2) ? (overall_minute - TIME2) : TIME2 - overall_minute;
	if(time_diff > time) {
		time_diff = time;
		min_time = TIME2;
		min_arrhour = 11; 
		min_arrmin = 52;
	}

	time = (overall_minute > TIME3) ? (overall_minute - TIME3) : TIME3 - overall_minute;
	if(time_diff > time) {
		time_diff = time;
		min_time = TIME3;
		min_arrhour = 13; 
		min_arrmin = 31;
	}
	

	time = (overall_minute > TIME4) ? (overall_minute - TIME4) : TIME4 - overall_minute;
	if(time_diff > time) {
		time_diff = time;
		min_time = TIME4;
		min_arrhour = 15; 
		min_arrmin = 0;
	}

	time = (overall_minute > TIME5) ? (overall_minute - TIME5) : TIME5 - overall_minute;
	if(time_diff > time) {
		time_diff = time;
		min_time = TIME5;
		min_arrhour = 16; 
		min_arrmin = 8;
	}

	time = (overall_minute > TIME6) ? (overall_minute - TIME6) : TIME6 - overall_minute;
	if(time_diff> time) {
		time_diff = time;
		min_time = TIME6;
		min_arrhour = 17; 
		min_arrmin = 55;
	}

	time = (overall_minute > TIME7) ? (overall_minute - TIME7) : TIME7 - overall_minute;
	if(time_diff > time) {
		time_diff = time;
		min_time = TIME7;
		min_arrhour = 21; 
		min_arrmin = 20;
	}

	time = (overall_minute > TIME8) ? (overall_minute - TIME8) : TIME8 - overall_minute;
	if(time_diff > time) {
		time_diff = time;
		min_time = TIME8;
		min_arrhour = 23; 
		min_arrmin = 58;
	}

	printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", min_time/60, min_time%60, min_arrhour, min_arrmin);
}