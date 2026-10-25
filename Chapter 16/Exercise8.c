#include<stdio.h>

struct color {
	int red, green, blue;
};

//Part a : 
const struct color MAGENTA_A = {255, 0, 255};
//Part b : 
const struct color MAGENTA_B = {.red = 255, .blue = 255};