#include<stdio.h>
#define PI 3.14159265

struct Point {int x, y;};

struct Shape {
	int shape_kind; //RECTANGLE or CIRCLE
	struct Point center;

	union {
		struct {
			int height, width;
		} rectangle;

		struct {
			int radius;
		} circle;
	} u;
};

//Part a : 
double ComputeArea(struct Shape shape) {
	if(shape.shape_kind == RECTANGLE) return shape.u.rectangle.height * shape.u.rectangle.width;  
	else if (shape.shape_kind == CIRCLE) return PI * shape.u.circle.radius * shape.u.circle.radius; 
}

//Part b : 
struct Shape Move(struct Shape shape, int x, int y) {
	struct Shape modified = shape;
	modified.center.x += x;
	modified.center.y += y;
	return modified;
}

//Part c : 
struct Shape Scale(struct Shape shape, double scale) {
	struct Shape modified = shape;
	if(modified.shape_kind == RECTANGLE) {
		modified.u.rectangle.height *= scale;
		modified.u.rectangle.width *= scale;
	}
	else if (modified.shape_kind == CIRCLE) modified.u.circle.radius *= scale;

	return modified;
}