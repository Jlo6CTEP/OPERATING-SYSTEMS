#include <stdio.h>
#include <stdlib.h>


void* my_realloc(void* a, int size);


int main () {
	int* a = (int*)malloc(10*sizeof(int));
	for (int i = 0; i < 10; i++) {
		a[i] = i;
		printf("%d ", a[i]);
	}
	printf("\n");
	a = my_realloc(a, 20*sizeof(int));

	for (int i = 0; i < 15; i++) {
		printf("%d ", a[i]);
	}
}


void* my_realloc(void* a, int size) {
	char* in = (char*)a;
	if (size == 0) {
		free(in);
		return NULL;
	} else if (in == NULL) {
		return malloc(size);
	} else {
		char* ptr = (char*)malloc(size);
		for (int i = 0; i < size; i++) 
			ptr[i] = in[i];
		return ptr;
	}		
}