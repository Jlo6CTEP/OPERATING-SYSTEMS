#include <signal.h>
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
char kill_message[16] = "Kill \n\0";
char stop_message[16] = "Stop \n\0";
char usr_message[16] = "Usr1 \n\0";

void kill_handler() {
	printf("%s",kill_message);
}

void stop_handler() {
	printf("%s",stop_message);
}

void usr_handler() {
	printf("%s",usr_message);
}


int main() {
	while(1) {
		signal(SIGKILL,kill_handler);
		signal(SIGUSR1,usr_handler);
		signal(SIGSTOP,stop_handler);	
	}
	return 0;
}