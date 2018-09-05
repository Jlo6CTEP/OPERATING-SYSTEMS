#include <stdio.h>

void bubble_sort(int *a, int size);


int main() {
	int array[11] = {10,9,8,7,6,5,4,3,2,1,0};
	bubble_sort(array, 11);
	for (int i = 0; i < 11; i++) {
		printf("%d ",array[i]);
	}
	return 0;
}

void bubble_sort(int *a, int size) {
	int n = size;
	int swapped = 1;
	while (swapped) {
	swapped = 0;
		for (int i = 1; i <= n-1; i++) {
			if (a[i-1] > a[i]) {
				int temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
				swapped = 1;
			}
		}
	}
}