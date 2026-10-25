#include<stdio.h>
#include<assert.h>

struct fraction {
	int numerator, denominator;
};

int GCD(int a, int b) {
	while (b != 0) {
        int temp = b;
        b = a % b; // b menjadi sisa pembagian
        a = temp;  // a mengambil nilai lama dari b
    }
	return a;
}

//Part a : 
struct fraction Reduce(struct fraction frac) {
	assert(frac.denominator != 0);
	int gcd = GCD(frac.numerator, frac.denominator);
	return (struct fraction) {.numerator = frac.numerator/gcd, .denominator = frac.denominator / gcd};
}

//Part b : 
struct fraction Add (struct fraction frac1, struct fraction frac2) {
	assert(frac1.denominator != 0 && frac2.denominator != 0);
	return Reduce( (struct fraction) {.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator, 
							.denominator = frac1.denominator * frac2.denominator});
}

//Part c : '
struct fraction Subtract (struct fraction frac1, struct fraction frac2) {
	assert(frac1.denominator != 0 && frac2.denominator != 0);
	return Reduce( (struct fraction) {.numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator, 
							.denominator = frac1.denominator * frac2.denominator});
}

//Part d : 
struct fraction Multiply (struct fraction frac1, struct fraction frac2) {
	assert(frac1.denominator != 0 && frac2.denominator != 0);
	return Reduce( (struct fraction) {.numerator = frac1.numerator * frac2.numerator, 
									  .denominator = frac1.denominator * frac2.denominator});
}

//Part e : 
struct fraction Divide (struct fraction frac1, struct fraction frac2) {
	assert(frac1.denominator != 0 && frac2.denominator != 0);
	return Reduce( (struct fraction) {.numerator = frac1.numerator * frac2.denominator, 
									  .denominator = frac1.denominator * frac2.numerator});
}

void Print(struct fraction frac, char* msg) {
	printf("%s : numerator = %d, denominator = %d\n", msg, frac.numerator, frac.denominator);
}

int main(void) {
	struct fraction frac1 = {.numerator = 1, .denominator = 20};
	struct fraction frac2 = {.numerator = 4, .denominator = 20};
	Print(Add(frac1, frac2), "Add");
	Print(Subtract(frac1, frac2), "Subtract");
	Print(Multiply(frac1, frac2), "Multiply");
	Print(Divide(frac1, frac2), "Divide");
}