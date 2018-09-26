#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include<stdlib.h>

void stop_handle() {
	exit(1);
}

int main() {
	int id1;
	int id2;
	int status;
	id1 = fork();	
	if (id1 != 0) {
		printf("Forking 1st child with id %d \n\0 %s",id1);
	}
	
	int pdes[2];
	
	if (id1 != 0) {
		id2 = fork();
		if (id2 != 0) {
			printf("Forking 2nd child with id %d \n\0 %s",id2);			
		}
		if (pipe(pdes) != -1) {
			write(pdes[1],&id2,4);
			close(pdes[1]);			
		}
	}
	
	if (id1 != 0 && id2 != 0) {
		printf("Sending ppid to 1st child \n\0 %s");
		int parrent_id = getppid();
		printf("Waiting for 2nd child \n\0 %s");
		waitpid(id2,&status,0);
		printf("2nd child state changed \n\0 %s");
	}

	if (id1 == 0) {
		read(pdes[0],&id2,4);
		close(pdes[0]);
		sleep(4);
		printf("Killing 2nd child \n\0 %s");
		kill(id2, SIGSTOP);
	}

	if (id2 == 0) {
		signal(SIGSTOP, stop_handle);
		sleep(5);
	}
	printf("Process %d returns\n\0",getpid());
	return 0;
}