#include<stdio.h>
#include<ctype.h>
#define NUM 12

int check (int, int, int); //Problem 2 : 
int gcd(int, int); //Problem 3 :
int day_of_year(int, int, int); //Problem 4 :  
int num_digits(int); //Problem 5 :
int digits(int, int); //Problem 6 :
int largest(int[], int); //Problem 10a : 
double average(int[], int); //Problem 10b
int num_positive(int[], int); //Problem 10c
float compute_GPA(char[], int); //Problem 11
double inner_product(double[], double[], int); //Problem 12


int main() {
	int num_problem = NUM;

	switch(num_problem) {
		case 2 : {
			printf("Problem 2 : \n");
			int x, y, n;
			printf("x = "); scanf("%d", &x);
			printf("y = "); scanf("%d", &y);
			printf("n = "); scanf("%d", &n);
			printf("Check = %d\n", check(x,y,n)); break;
		}
		

		case 3 : {
			int m, n;
			printf("Enter 2 integers : "); scanf("%d%d", &m, &n);
			printf("Greatest common divisor : %d\n", gcd(m,n)); break;
		}
		
		case 4 : {
			int month, day, year; 
			printf("Month = "); scanf("%d", &month);
			printf("Day = "); scanf("%d", &day);
			printf("Year = "); scanf("%d", &year);
			printf("Day of year = %d\n", day_of_year(month, day, year)); break;
		}

		case 5 : {
			int n; 
			printf("n = "); scanf("%d", &n);
			if(n < 0) return -1;
			printf("Number of digit = %d\n", num_digits(n)); break;
		}

		case 6 : {
			int n,k; 
			printf("n = "); scanf("%d", &n);
			printf("Digit from right = "); scanf("%d", &k);
			if(n < 0 || k < 0) return -1;
			printf("Digit = %d\n", digits(n,k)); break;
		}

		case 10 : {
			int n; 
			printf("Array size = "); scanf("%d", &n);

			int a[n];
			printf("Enter %d numbers : ", n);
			for(int i = 0; i<n; i++) scanf("%d", &a[i]);
			printf("10a. Largest element in a = %d\n", largest(a, n));
			printf("10b. Average of all elements in a = %lf\n", average(a, n)); 
			printf("10c. Number of positive elements in a = %d\n", num_positive(a, n));  break;
		}

		case 11 : {
			int n; 
			printf("Number of grades = "); scanf("%d", &n);
			char grades[n];
			printf("Enter %d grades : ", n);
			for(int i = 0; i<n; i++) scanf(" %c", &grades[i]);
			printf("GPA = %.2f\n", compute_GPA(grades, n)); break;
		}
		
		case 12 : {
			int n; 
			printf("Array size = "); scanf("%d", &n);

			double a[n];
			printf("Enter %d numbers : ", n);
			for(int i = 0; i<n; i++) scanf("%lf", &a[i]);

			double b[n];
			printf("Enter %d numbers : ", n);
			for(int i = 0; i<n; i++) scanf("%lf", &b[i]);

			printf("Inner product = %lf\n", inner_product(a, b, n));
		}
	}
}

//Problem 2 : 
int check(int x, int y, int n) {
	return (x >= 0 && x < n && y >= 0 && y < n) ? 1 : 0;
}

//Problem 3 : 
int gcd(int m, int n) {
	//Swtich m and n so that m > n : 
	if(n > m) {
		int temp = n;
		n = m;
		m = temp;	
	}

	//Euclid algorithm :
	while(n != 0) {
		int t = m%n;
		m = n;
		n = t;
	}
	return m;
}

//Problem 4 : 
int day_of_year(int month, int day, int year) {
	if( (month > 12 || month < 1) || (day < 1 || day > 31) || year <= 0 ) return -1;
	
	int date[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	//Tahun kabisat : 
	if(year%4 == 0) {
		//Particularly for divisible by 100 : 
		if(year % 100 == 0) {
			if(year % 400 == 0) date[1] = 29; //Sudah pasti kabisat
		}
		else date[1] = 29; //Sudah pasti kabisat
	}

	//Next checking for day : 
	if(day > date[month - 1]) return -1;

	int num_day = 0;
	for(int i = 0; i<month-1; i++) num_day += date[i];
	return num_day + day;
}

//Problem 5 : 
int num_digits(int n) {
	int digit = 1; 
	int temp = n;
	while( (temp /= 10) != 0) digit++;
	return digit;
}

//Problem 6 : 
int digits(int n, int k) {
	int temp = n; 

	for(int i = 0; i<k-1; i++) temp /= 10;
	return temp%10;
}

//Problem 10a : 
int largest(int a[], int n) {
	int max = a[0];
	for(int i = 1; i<n; i++) max = (max < a[i]) ? a[i] : max;
	return max;
}

//Problem 10b : 
double average(int a[], int n) {
	int sum = 0; 
	for(int i = 0; i<n; i++) sum += a[i];
	return sum/(double)n;
}

//Problem 10c : 
int num_positive(int a[], int n) {
	int count = 0; 
	for(int i = 0; i<n; i++) count += (a[i] > 0);
	return count;
}

//Problem 11 : 
float compute_GPA(char grades[], int n) {
	float sum = 0; 

	for(int i = 0; i<n; i++) {
		switch(toupper(grades[i])) {
			case 'A' : sum += 4; break;
			case 'B' : sum += 3; break;
			case 'C' : sum += 2; break;
			case 'D' : sum += 1; break;
			case 'F' : sum += 0; break;
			default : return -1;
		}
	}
	return sum / n;
}

//Problem 12 : 
double inner_product(double a[], double b[], int n) {
	double sum = 0; 
	for(int i = 0; i<n; i++) sum += a[i] * b[i];
	return sum;
}