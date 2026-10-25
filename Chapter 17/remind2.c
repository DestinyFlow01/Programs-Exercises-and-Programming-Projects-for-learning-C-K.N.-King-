#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MSG_NUM 60
#define REM_LEN 50

int readline(char* reminder, int max_length);

int main() {
	int day, msg_num = 0; 
	char reminder[REM_LEN+1] = {'\0'}, *message[MSG_NUM] = {'\0'}, day_str[3] = {'\0'};

	//Reading and sorting : 
	for(;;) {
		if(msg_num >= MSG_NUM) {
			printf("No space left\n\n"); break;
		}

		//Input day and reminder
		printf("Enter day and reminder : ");
		scanf("%2d", &day);
		if(day < 0) {
			printf("Day must be positive. Terminating...\n");
			exit(EXIT_FAILURE);
		}
		if(day == 0) break;
		sprintf(day_str, "%2d", day);
		readline(reminder, REM_LEN);

		//Comparing : 
		int i; 
		for(i = 0; i<msg_num; i++) {
			if(strcmp(day_str, message[i]) <= 0) break;
		}
		
		for(int j = msg_num; j > i; j--) message[j] =  message[j-1];

		if( 
		(
			message[i] = malloc(sizeof(char) * (2 + 1 + strlen(reminder)))
		) == NULL) {
			printf("Malloc fail. No space left. Terminating...\n");
			return EXIT_FAILURE;
		}
		strcpy(message[i], day_str);
		strcat(message[i], reminder);

		msg_num++;
	}

	//Printing :
	printf("\nDay Reminder\n");
	for(int i = 0; i < msg_num; i++) {
		printf("%s\n", message[i]);
	} 
}

int readline(char* reminder, int max_length) {
	int ch;
	int i = 0; 
	while((ch = getchar()) != '\n' && i < max_length) {
		reminder[i++] = ch;
	}
	reminder[i] = '\0';
	return i;
}