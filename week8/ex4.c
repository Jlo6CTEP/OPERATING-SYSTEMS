#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h> 

int main() {
	while(1) {
		int* ptr = (int*)malloc(1024*1024*100);
		memset(ptr,0,1024*1024*100);
		sleep(1);

		struct rusage usage;
		
		getrusage(RUSAGE_SELF, &usage);

		printf("%d %d %d\n", usage.ru_maxrss, usage.ru_minflt, usage.ru_majflt);
	}
	return 0;
}