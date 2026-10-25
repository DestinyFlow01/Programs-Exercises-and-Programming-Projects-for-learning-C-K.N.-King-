#include<stdio.h>

#define AVG(x,y) (x+y)/2
#define AREA(x,y) (x)*(y)

#define AVG_FIX(x,y) (((x)+(y))/2)
#define AREA_FIX(x,y) ((x)*(y))

int main(void) {
	printf("Not fixed : \n");
	printf("5/AVG(%d, %d) = %d\n", 2, 4, 5/AVG(2, 4));	//0
	printf("10./AREA(%d, %d) = %lf\n", 10, 3, 10./AREA(10,3)); //3

	printf("\nFixed : \n");
	printf("5/AVG(%d, %d) = %d\n", 2, 4, 5/AVG_FIX(2, 4));	// 1
	printf("10./AREA(%d, %d) = %lf\n", 10, 3, 10./AREA_FIX(10,3)); // 1/3
}