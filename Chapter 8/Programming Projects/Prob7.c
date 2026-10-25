#include<stdio.h>

#define ARRAYSIZE 5

int main() {
	int arr[ARRAYSIZE][ARRAYSIZE] = {0};
	int row_total[ARRAYSIZE] = {0}, col_total[ARRAYSIZE] = {0};
	
	for(int i = 0; i<ARRAYSIZE; i++) {
		printf("Enter row %d: ", i+1);
		
		for(int j = 0; j<ARRAYSIZE; j++) {
			scanf("%d", &arr[i][j]);
			row_total[i] += arr[i][j];
			col_total[j] += arr[i][j];
		}
	}

	printf("Row totals : ");
	for(int i = 0; i<ARRAYSIZE; i++) printf("%d ", row_total[i]);
	printf("\nColumn totals : ");
	for(int i = 0; i<ARRAYSIZE; i++) printf("%d ", col_total[i]);
	printf("\n");
}