#include<stdio.h>
#include<stdbool.h>

int main() {
	int n; 
	printf("This program creates a magic square of a specified size.\nThe size must be an old number between 1 and 99.\n");
	printf("Enter size of magic square : "); scanf("%d", &n);

	if(n%2 == 0) return -1;

	bool track_passed[n][n];
	int track[n][n]; 
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			track_passed[i][j] = false;
			track[i][j] = 0;
		} 
	}

	//Initial position at the center of the first row : 
	int row = 0, col = (n-1)/2;
	int num_traversed = 1;
	track_passed[row][col] = true; 
	track[row][col] = 1;

	while(num_traversed < n*n) {
		int row_dummy = (row-1)%n;
		if(row_dummy < 0) row_dummy += n;
		int col_dummy = (col+1)%n;
		if(col_dummy < 0) col_dummy += n;
		if(!track_passed[row_dummy][col_dummy]) {
			row = row_dummy; col = col_dummy;
		}
		else row = (row + 1) % n;

		track_passed[row][col] = true;
		track[row][col] = (++num_traversed);
	}

	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) printf("%3d ", track[i][j]);
		printf("\n");
	}
	printf("\n");
}