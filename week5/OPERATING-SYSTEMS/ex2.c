#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {
	char input[100];
	fgets(input, 100, stdin);
	for (int i = strlen(input)-1; i>= 0; i--) {
		printf("%c",input[i]);
	}
	printf("\n");
	return 0;
}