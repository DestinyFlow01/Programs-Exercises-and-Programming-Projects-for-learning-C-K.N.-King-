#include<stdio.h>

#define ARRAYSIZE 5

int main() {
	double score[ARRAYSIZE][ARRAYSIZE] = {0};
	double total[ARRAYSIZE] = {0}, high[ARRAYSIZE] = {-1}, low[ARRAYSIZE] = {2000}, average_quiz[ARRAYSIZE] = {0};
	
	for(int i = 0; i<ARRAYSIZE; i++) {
		printf("Enter row %d: ", i+1);
		
		for(int j = 0; j<ARRAYSIZE; j++) {
			scanf("%lf", &score[i][j]);
			total[i] += score[i][j];
			high[j] = (high[j] < score[i][j]) ? score[i][j] : high[j];
			low[j] = (low[j] > score[i][j]) ? score[i][j] : low[j];
			average_quiz[j] += score[i][j]/ARRAYSIZE;
		}
	}

	printf("Total score for each student : ");
	for(int i = 0; i<ARRAYSIZE; i++) printf("%5.1lf ", total[i]);
	printf("\nAverage score for each student : ");
	for(int i = 0; i<ARRAYSIZE; i++) printf("%5.1lf ", total[i]/ARRAYSIZE);
	printf("\nAverage score for each quiz : ");
	for(int i = 0; i<ARRAYSIZE; i++) printf("%5.1lf ", average_quiz[i]);
	printf("\nHigh score for each quiz : ");
	for(int i = 0; i<ARRAYSIZE; i++) printf("%5.1lf ", high[i]);
	printf("\nLow score for each quiz : ");
	for(int i = 0; i<ARRAYSIZE; i++) printf("%5.1lf ", low[i]);

	printf("\n");	
}