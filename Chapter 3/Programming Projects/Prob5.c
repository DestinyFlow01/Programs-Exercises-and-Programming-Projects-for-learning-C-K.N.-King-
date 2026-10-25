#include<stdio.h>

int main(void) {
	int num[16];
	printf("Enter the numbers from 1 to 16 in any order: ");

	for(int i = 0; i<=15; i++) scanf("%d",&num[i]);

	//Printing square : 
	for(int i = 0; i<16; i++) {
		printf("%3d ", num[i]);

		if(i%4 == 3) printf("\n");
	}

	int row_sum[4] = {0,0,0,0}, col_sum[4] = {0,0,0,0}, diagonal[2] = {0,0};
	for(int i = 0; i<4; i++) {
		for(int j = 0; j<4; j++) {
			row_sum[i] += num[4*i + j];
			col_sum[i] += num[4*j + i];
		}
	} 

	for(int i = 0; i<16; i+=5) diagonal[0] += num[i];
	for(int i = 3; i<15; i+=3) diagonal[1] += num[i];

	printf("Row sums : ");
	for(int i = 0; i<4; i++) printf(" %d ", row_sum[i]);
	printf("\nColumn sums : ");
	for(int i = 0; i<4; i++) printf(" %d ", col_sum[i]);
	printf("\nDiagonal sums : ");
	for(int i = 0; i<2; i++) printf(" %d ", diagonal[i]);
	printf("\n");
}