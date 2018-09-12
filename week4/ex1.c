#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>



int main()
{
        pid_t n;
		pid_t l = fork();
        /* fork a child process */
        n = getpid();

        printf("Hello from child [%d]\n",n);

        n = getppid();

        printf("Hello from parent [%d]\n",n);

        return 0;
}