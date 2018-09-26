#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	char input[16] = "string1\n\0";
	char output[16];
	int pdes[2];
	if (pipe(pdes) != -1) {
		write(pdes[1],input,16);
		close(pdes[1]);
		if (fork() == 0) {
			read(pdes[0],output,16);
			close(pdes[0]);
			printf("%s",output);
		}			
	}
	return 0;
}