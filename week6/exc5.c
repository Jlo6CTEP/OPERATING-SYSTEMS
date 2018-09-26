 #include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int main() {
	char message[16] = "Imma Alive";
	int id = fork();
	if (id == 0) {
		while(1) {
			printf("\n%s",message);
			sleep(1);
		}
	} else {
		sleep(10);
		kill(id, SIGTERM);
	}
	return 0;
}                                                                                                                                