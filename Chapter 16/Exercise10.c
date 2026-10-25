#include<stdio.h>

struct point{int x, y;};
struct Rectangle {
	struct point upper_left;
	struct point lower_right;
};

//Part a : Compute area : 
int ComputeArea(struct Rectangle r) {
	return (r.lower_right.x - r.upper_left.x) * 
			(r.lower_right.y - r.upper_left.y);
}

//Part b : Compute center : 
struct point ComputeCenter(struct Rectangle r) {
	return (struct point) {
		.x = (r.lower_right.x + r.upper_left.x) / 2, 
		.y = (r.lower_right.y + r.upper_left.y) / 2
	};
}

//Part c : 
struct Rectangle Shift(struct Rectangle r, double x, double y) {
	return (struct Rectangle) {
		.lower_right = {.x = r.lower_right.x + x, .y = r.lower_right.y - y}, 
		.upper_left = {.x = r.upper_left.x + x, .y = r.upper_left.y - y}
	};
}

//Part d : 
_Bool Inside(struct Rectangle r, struct point p) {
	return (r.upper_left.x > p.x && r.lower_right.x < p.x) && 
			(r.upper_left.y < p.y && r.lower_right.y > p.y);
}