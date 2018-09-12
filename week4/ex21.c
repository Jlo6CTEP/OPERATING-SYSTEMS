#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>



int main()
{
        pid_t pid;
	for(int x = 0; x < 3; x++) 
        pid = fork();

    sleep(3);
	return 0;
        
}