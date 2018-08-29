#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int*y);
int main() {
	char number[100];
		
	printf("%s\n","Input 1 integer");
	scanf("%s", &number);	
	int x1 = atoi(number);
	printf("%s\n","Input 2 integer");
	scanf("%s", &number);	
	int x2 = atoi(number);
	swap(&x1,&x2);
	printf("%d %d\n",x1,x2);
}

void swap(int *ptrx, int *ptry) {
	int x = *ptrx;
	int y = *ptry;

	*ptrx = y;
	*ptry = x;
	
}