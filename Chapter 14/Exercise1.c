#include<stdio.h>

#define CUBE(x) ((x)*(x)*(x)) 		//1a
#define REMAINDER_4(n) ( (n)%4 ) 	//1b 
#define PROD(x,y) ( (x)*(y) < 100 ) //1c

int main(void) {
	double x, y;
	int n; 

	printf("Exercise 1a : \n");
	printf("%lf cubed = %lf\n", 5., CUBE(5.)); //125
	printf("%lf cubed = %lf\n", 5. + 2. * -3., CUBE(5. + 2. * -3.)); //-1
	
	printf("\nExercise 1b : \n");
	printf("%d mod 4 = %d\n", 5, REMAINDER_4(5) );
	printf("%d mod 4 = %d\n", 10 * 5, REMAINDER_4(10 * 5) );

	printf("\nExercise 1c : \n");
	printf("(x = %lf, y = %lf) : %d\n", 10.2, 3.1, PROD(10.2, 3.1) );
	printf("(x = %lf, y = %lf) : %d\n", 10.2, 10.1, PROD(10.2, 10.1) );
	printf("(x = %lf, y = %lf) : %d\n", 10.2, 10.1+3, PROD(10.2, 10.1+3) );
}