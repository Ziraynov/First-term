#include <stdio.h>
int main()
{
	float a, v;
	printf_s("enter the length of the edge of the cube:");
	scanf_s("%f", &a);
	v = a * a * a;
	printf("the volume of the cube is:%.3f", v);
	return 0;
}