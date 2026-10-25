#include<stdio.h>

int main(void) {
	int d = 1, m = 1, y = 1, min_d = 99, min_m = 99, min_y = 99;

	while(1) {
		printf("Enter date (mm/dd/yy) : "); scanf("%d/%d/%d", &m, &d, &y);	

		if(d == 0 && y == 0 && m == 0) break;

		if(min_y > y) min_y = y, min_d = d, min_m = m;
		else if(min_y == y) {
			if(min_m > m) min_d = d, min_m = m;
			else if (min_m == m) {
				if(min_d > d) min_d = d;
			}
		}
	}
	printf("%d/%d/%.2d is the earliest date\n", min_m, min_d, min_y); 
	 
	
}