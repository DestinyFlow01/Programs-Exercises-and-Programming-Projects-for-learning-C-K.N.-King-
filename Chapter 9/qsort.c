#include<stdio.h>
#define N 10

void QuickSort(int[], int, int);
int Split(int[], int, int);

int main() {
	int a[N];
	printf("Enter 10 numbers to be sorted : ");
	for(int i = 0; i<N; i++) scanf("%d", &a[i]);

	//Sorting : 
	QuickSort(a, 0, N-1);

	//Print result : 
	printf("In sorted order : ");
	for(int i = 0; i<N; i++) printf("%d ", a[i]);
	printf("\n");
}

void QuickSort(int a[], int low, int high) {
	if(low >= high) return; 

	//else : 
	int middle = Split(a, low, high);
	QuickSort(a, low, middle - 1);
	QuickSort(a, middle + 1, high);
}

int Split(int a[], int low, int high) {
	int middle = a[low]; 

	for(;;) {
		//High first :
		while(low < high && middle <= a[high]) high--;
		if(low >= high) break;
		a[low++] = a[high]; 

		//Low then : 
		while(low < high && a[low] <= middle) low++;
		if(low >= high) break;
		a[high--] = a[low]; 
	}
	a[high] = middle;
	return high;
}