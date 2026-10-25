#include<stdio.h>
#define N 4

int main(void) {
	double a[N][N] = {0};

	//Making identity matrix :  
	for(double* p = a[0]; p < a[N]; p += (N+1)) *p = 1.0;
	
	//Printing matrix :
	int index = 0; 
	printf("Matrix : ");
	for(double* p = a[0]; p < a[N]; p++) {
		if(index++ % N == 0) printf("\n");
		printf("%.lf ", *p);
	}
	printf("\n");
}