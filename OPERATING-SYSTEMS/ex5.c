#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void isoTriangle(int height);
void rectTriangle(int height);
void arrow(int height);
void square(int height);

int main (int argc, char *argv) {
	char number[100];
	
	printf("%s\n","provide height");
	scanf("%s",&number);
	int height = atoi(number);

	printf("%s\n","provide mode");
	scanf("%s",&number);
	int mode = atoi(number);

	switch(mode) {
		case 0:
			isoTriangle(height);
		break;
		case 1:
			rectTriangle(height);
		break;
		case 2:
			arrow(height);
		break;
		case 3:
			square(height);
		break;

		default:
			isoTriangle(height);
		
	}
	
}
void isoTriangle(int height) {
	char string[2*height];
	for (int x = 0; x <= 2*height-2; x++) {
		string[x] = ' ';
	}
		string[2*height-1] ='\0';
	int middle = height-1;
	
	for (int x = 0; x <= height-1; x++) {
		string[middle+x] = '*';
		string[middle-x] = '*';
		printf("%s\n",string);
	}
}
void rectTriangle(int height) {

	char string[height+1];
		for (int x = 0; x <= height-1; x++) {
		string[x] = ' ';
	}
	string[height] ='\0';

	for (int x = 0; x <= height-1; x++) {
		string[x] = '*';
		printf("%s\n",string);
	}	
}
void arrow(int height) {
	 char string[2*height];
          for (int x = 0; x <= height-1; x++) {
               string[x] = ' ';
	      }
	      string[height] ='\0';
	 for (int x = 0; x <= height-1; x++ ) {
	 	string[x] = '*';
		printf("%s\n",string);
	 	
	 }
	 for (int x = height-1;x >= 0; x--) {
	 	string[x] = ' ';
	 printf("%s\n",string);
	 	
	 } 
	 
}
void square(int height) {
	char string[height+1];
	for (int x = 0; x <= height-1; x++) {
		string[x] = '*';
	}			
	string[height] ='\0';
	for (int x = 0; x <= height-1; x++) {
		printf("%s\n",string);
	}			
}