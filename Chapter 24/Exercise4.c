#include<stdio.h>
#include<math.h>
#include<errno.h>
#include<stdlib.h>
double try_math_fcn( double (*) (double), double, char* );
#define TRY_MATH_FCN(func, x) try_math_fcn(func, x, "Error in the call of " #func)

int main(void) {
	double x = 3000; 
	printf("Result = %lg\n", 
		TRY_MATH_FCN(exp, x));
}

/// @brief Try math function from Exercise 4
/// @param fcn pointer to function in <math.h> library with parameter and return type of double
/// @param x input to the function
/// @param msg error message when the call fails
/// @return if succeed, it will return the result. If fails, it gets perror
double try_math_fcn( double (*fcn) (double), double x, char* msg) {
	errno = 0; 
	double y = fcn(x);
	if(errno != 0) {
		perror(msg);
		exit(EXIT_FAILURE);
	}
	return y;
}