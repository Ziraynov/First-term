#include <stdio.h>
int main()
{
	float x, y;
	printf_s("input x: ");
	scanf_s("%f,", &x);
	printf_s("input y: ");
	scanf_s("%f", &y);

	if ((x * x) + (y * y) == 1)
		printf_s("mojno");
	else
		printf_s("nelzy");
	return 0;
}