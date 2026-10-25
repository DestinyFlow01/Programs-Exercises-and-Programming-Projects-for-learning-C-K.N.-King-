#include<stdio.h>

#define CHECK(x,y,n) ( ((x) >= 0 && (x) <= (n)-1 && (y) >= 0 && (y) <= (n)-1) )
#define POW2(x) ((x) * (x))
#define POW3(x) ((POW2(x)) * (x))
#define POW4(x) ((POW2(x)) * (POW2(x)))
#define POW5(x) ((POW4(x)) * (x))
#define POLYNOMIAL(x) (3*POW5(x) + 2*POW4(x) - 5 * POW3(x) - POW2(x) + 7*(x) - 6)

