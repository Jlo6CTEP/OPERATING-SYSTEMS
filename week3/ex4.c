#include <stdio.h>
void quick_sort(int* array, int l, int r);
int partition(int* array, int l, int r);


int main() {

	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	
	quick_sort(array, 0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

void quick_sort(int* array, int l, int r) {
	if (l < r) {
		int pivot = partition(array, l, r);
		quick_sort(array, l, pivot-1);
		quick_sort(array,pivot+1,r);
	}
}


int partition(int *array, int l, int r) {
	int pivot = array[r];
	int i = l;
	for (int j = l; j <= r-1; j++) {
		if (array[j] < pivot) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	int temp = array[i];
	array[i] = array[r];
	array[r] = temp;
	return i;
}