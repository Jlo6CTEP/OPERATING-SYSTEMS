#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	while(1) {
		int* ptr = (int*)malloc(1024*1024*10);
		memset(ptr,0,1024*1024*10);
		sleep(1);
	}
	return 0;
}