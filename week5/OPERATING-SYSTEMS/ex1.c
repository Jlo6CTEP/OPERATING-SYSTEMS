#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(int argc, char* argv[]) {
	int x1;
	float x2;
	double x3;
	x1 = INT_MAX;
	x2 = FLT_MAX;
	x3 = DBL_MAX;

	printf("%d\n", x1);
	printf("%f\n", x2);
	printf("%f\n", x3);
	printf("%d\n",sizeof(x1));
	printf("%d\n",sizeof(x2));
	printf("%d\n",sizeof(x3));
	return 0;
}