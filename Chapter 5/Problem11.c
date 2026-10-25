#include<stdio.h>

/*
Area code Major city
229 Albany
404 Atlanta
470 Atlanta
478 Macon
678 Atlanta
706 Columbus
762 Columbus
770 Atlanta
912 Savannah
*/
int main(void) {
	int area_code; scanf("%d", &area_code);

	switch(area_code) {
		case 229 : printf("Albany"); break;
		case 404 : 
		case 770 : 
		case 678 : 
		case 470 : printf("Atlanta"); break;
		case 478 : printf("Macon"); break;
		case 706 : 
		case 762 : printf("Columbus"); break;
		case 912 : printf("Savannah"); break;
		default : printf("Area code not recognized");
	}

	printf("\n");
}