#include<stdio.h>

struct color {
	int red, green, blue;
};

//Part a : 
struct color make_color(int red, int green, int blue) {
	int red_color = (red < 0) ? 0 : ( (red > 255) ? 255 : red );
	int green_color = (green < 0) ? 0 : ( (green > 255) ? 255 : green );
	int blue_color = (blue < 0) ? 0 : ( (blue > 255) ? 255 : blue );
	return (struct color) {red_color, green_color, blue_color};
}

//Part b : 
int getRed(struct color col) {return col.red;}

//Part c : 
_Bool equal_color(struct color c1, struct color c2) {
	return (c1.red == c2.red) && (c1.blue == c2.blue) && (c1.green == c2.green);
}

//Part d : 
struct color brighter(struct color c) {
	if(c.blue == 0 && c.green == 0 && c.red == 0) return (struct color) {3, 3, 3};
	else {
		int red, green, blue;
		if(c.red > 0 && c.red < 3) red = 3/0.7;
		else if (c.red / 0.7 > 255) red = 255;
		else red = c.red / 0.7;

		if(c.green > 0 && c.green < 3) green = 3/0.7;
		else if (c.green / 0.7 > 255) green = 255;
		else green = c.green / 0.7;

		if(c.blue > 0 && c.blue < 3) blue = 3/0.7;
		else if (c.blue / 0.7 > 255) blue = 255;
		else blue = c.blue / 0.7;

		return (struct color) {red, green, blue};
	}
}
