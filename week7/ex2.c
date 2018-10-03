#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	scanf("%d",&size);
	int *ptr = (int*)malloc(size*sizeof(int));
	for (int i=0; i < size; i++) {
		ptr[i] = i;
	}

	for (int i=0; i < size; i++) {
		printf("%d ", ptr[i]);
	}	

	free(ptr);
		
	return 0;
}