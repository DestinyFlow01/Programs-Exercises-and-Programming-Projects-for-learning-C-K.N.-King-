#include<stdio.h>
#include<assert.h>

struct time {
	int hours, minutes, seconds;
};

struct time split_time(long total_seconds) {
	assert(total_seconds >= 0 && total_seconds <= 86400);

	struct time time;
	int temp;
	time.seconds = total_seconds % 60;
	temp = total_seconds / 60;
	time.minutes = temp % 60;
	time.hours = temp/60;
	return time;
}

void PrintStruct(struct time time) {
	printf("Seconds = %d, minutes = %d, hours = %d\n", time.seconds, time.minutes, time.hours);
}

int main(void) {
	long time_seconds = 5000;
	PrintStruct(split_time(time_seconds));
}