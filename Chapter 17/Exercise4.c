#include<stdlib.h>

struct point{int x, y;};
struct rectangle {
	struct point upper_left;
	struct point lower_right;
};
struct rectangle *p;

struct rectangle* InitializeRectangle() {
	struct rectangle *rectangle = malloc(sizeof(*rectangle));
	if(rectangle == NULL) exit(EXIT_FAILURE);
	rectangle->upper_left.x = 10;
	rectangle->upper_left.y = 25;
	
	rectangle->lower_right.x = 20;
	rectangle->lower_right.y = 15;
	return rectangle;
}