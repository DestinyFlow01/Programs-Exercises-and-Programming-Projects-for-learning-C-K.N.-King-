#include "quicksort.h"

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