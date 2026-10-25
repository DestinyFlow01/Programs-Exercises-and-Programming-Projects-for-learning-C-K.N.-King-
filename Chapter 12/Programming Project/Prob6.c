#include<stdio.h>
#define N 10

void QuickSort(int[], int*, int*);
int* Split(int[], int*, int*);

int main() {
	int a[N];
	printf("Enter 10 numbers to be sorted : ");
	for(int* p = a; p < a + N; p++) scanf("%d", p);

	//Sorting : 
	QuickSort(a, a, a + N-1);

	//Print result : 
	printf("In sorted order : ");
	for(int* p = a; p < a + N; p++) printf("%d ", *p);
	printf("\n");
}

void QuickSort(int a[], int* ptr_low, int* ptr_high) {
	if(ptr_low >= ptr_high) return; 

	//else : 
	int* ptr_middle = Split(a, ptr_low, ptr_high);
	QuickSort(a, ptr_low, ptr_middle - 1);
	QuickSort(a, ptr_middle + 1, ptr_high);
}

int* Split(int a[], int* ptr_low, int* ptr_high) {
	int middle = *ptr_low; 

	for(;;) {
		//High first :
		while(ptr_low < ptr_high && middle <= *ptr_high) ptr_high--;
		if(ptr_low >= ptr_high) break;
		*ptr_low++ = *ptr_high; 

		//Low then : 
		while(ptr_low < ptr_high && *ptr_low <= middle) ptr_low++;
		if(ptr_low >= ptr_high) break;
		*ptr_high-- = *ptr_low; 
	}
	*ptr_high = middle;
	return ptr_high;
}