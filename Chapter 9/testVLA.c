#include<stdio.h>
typedef unsigned int uint;

void InitializeVector(uint, uint[*]);
void PrintVector(uint, uint[*]);
void AddVector(uint, uint[*], uint[*], uint[*]);
void Concatenate(uint, uint, uint[*], uint[*], uint[*]);

int main(void) {
	//Just adding two vectors using VLA : 
	uint n; 
	printf("Input size of vector : "); scanf("%ud", &n);
	if(n == 0) return -1;

	//Declaring and defining 2 vectors : 
	uint a[n], b[n];
	InitializeVector(n,a); InitializeVector(n,b); 

	a[0] = 1; b[n-1] = 1;

	uint add[n];
	AddVector(n,a, b, add);
	PrintVector(n,add);

	//Concatenate two vectors :
	uint c[n + n]; 
	Concatenate(n,n, a, b, c);
	PrintVector(sizeof(c)/sizeof(uint), c);
}

void InitializeVector(uint n, uint a[n]) {
	for(int i = 0; i<n; i++) a[i] = 0;
}

void PrintVector(uint n, uint a[n]) {
	printf("\nVector = [");
	for(int i = 0; i<n; i++) printf(" %d ", a[i]);
	printf("]\n");
}

void AddVector(uint n, uint a[n], uint b[n], uint c[n]) {
	for(int i = 0; i<n; i++) c[i] = a[i] + b[i];
}

void Concatenate(uint m, uint n, uint a[m], uint b[n], uint c[m+n]) {
	//For a : 
	for(uint i = 0; i<m; i++) c[i] = a[i];
	//For b : 
	for(uint i = m; i<m+n; i++) c[i] = b[i-m];
}