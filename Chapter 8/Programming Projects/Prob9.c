#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	char field[10][10];
	for(int i = 0; i<10; i++) {
		for(int j = 0; j<10; j++) field[i][j] = '.';
	}
	bool pass[10][10] = {false};

	//Directions : 
	const short vertical[4] =   {0, 1, 0, -1};
	const short horizontal[4] = {1, 0, -1, 0};

	srand((unsigned) time(NULL));

	//Position : 
	int row = 0, col = 0, direction; 
	field[row][col] = 'A';
	pass[row][col] = true;
	int row_dummy, col_dummy;

	for(int i = 1; i<26; i++) {
		bool tried_direction[4] = {false};
	
		//Finding direction : 
		do {
			direction = rand() % 4;
			if(tried_direction[direction]) continue;

			tried_direction[direction] = true;
			row_dummy = row + vertical[direction];
			col_dummy = col + horizontal[direction];
			if(row_dummy >= 0 && row_dummy < 10 && col_dummy >= 0 && col_dummy < 10 && !pass[row_dummy][col_dummy]) break;
			
			bool all_true = true; 
			for(int j = 0; j<4; j++) all_true = all_true && tried_direction[j];
			
			if(all_true) {
				printf("Early termination\n");
				goto printing;
			}
			
		} while(1);
		
		row = row_dummy; col = col_dummy;
		pass[row][col] = true;
		field[row][col] = 'A' + i;
	}

	printing : 
	for(int i = 0; i<10; i++) {
		for(int j = 0; j<10; j++) putchar(field[i][j]);
		printf("\n");
	}
	printf("\n");
}