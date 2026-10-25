#include<stdio.h>

int main(void) {
	int a,b,c,d;
	printf("Enter 4 integers : "); scanf("%d%d%d%d", &a, &b, &c, &d);
	int max = a, min = a; 

	if(max < b) max = b;
	if(max < c) max = c;
	if(max < d) max = d;

	if(min > b) min = b;
	if(min > c) min = c;
	if(min > d) min = d;

	printf("Largest : %d\nSmallest : %d\n", max, min);
}