#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
	int file = open("/dev/random", O_RDONLY);
	char str[21];
	str[20] = '\0';
	read(file, str, 20);
	printf("%s\n",str);
	close(file);
	return 0;
}
