#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	int mode = O_WRONLY|O_CREAT;
	printf("alive\n"); 
	for (int i = 0; i < argc; i++){
		if (argv[i][0] == '-' && argv[i][1] == 'a')
			mode = O_WRONLY|O_APPEND;
	}
	char buff[1024*1024];
	long x = 0;
	int in = open("/dev/stdin", O_RDONLY);
	while(1){
		x = 0;
		printf(" %d", (int)x);
		while(read(in, &buff[x], 1) && buff[x] != EOF && x < 1024*1024) {
			if (buff[x] == EOF)
				break;
			x++;
			}
		printf("%s",buff);
		if (buff[x] == EOF)
			break;
		close(in);
		for (int i = 1; i < argc; i++){
			int file = open(argv[i], mode);
			write(file, buff, x);
			close(file);
		}
	}

	return 0;
}
