#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main (int argc, char *argv) {
	char number[100];
	scanf("%s",&number);
	int n = atoi(number);
	char string[2*n];
	for (int x = 0; x <= 2*n-2; x++) {
		string[x] = ' ';
	}
	string[2*n-1] ='\0';
	int middle = n-1;
	for (int x = 0; x <= n-1; x++) {
		string[middle+x] = '*';
		string[middle-x] = '*';
		printf("%s\n",string);
	}
}