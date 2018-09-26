#include <signal.h>
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
char message[128] = "Ctrl + C was pressed \n\0";
int counter = 1;

void sig_handler() {
	printf("%s",message);
	counter = 0;
}


int main() {
	while(counter) {
		sleep(1);
		signal(2,sig_handler);
	}
	return 0;
}