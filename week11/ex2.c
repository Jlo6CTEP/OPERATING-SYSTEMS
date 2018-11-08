#include <stdio.h>
#include <unistd.h>

int main() {
	setvbuf(stdout, NULL, _IOLBF, 256);
	char hello[5] = "hello";
	for (int i = 0; i < 5; i++) {
		printf("%c", hello[i]);
		sleep(1);
	}
	

	return 0;
}