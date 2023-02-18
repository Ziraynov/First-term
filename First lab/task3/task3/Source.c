#include <stdio.h>
int main()
{
	double a, b, c;
	int i = 0;
	printf_s("input number a: ");
	scanf_s("%lf", &a);
	printf_s("input number b: ");
	scanf_s("%lf", &b);
	printf_s("input number c: ");
	scanf_s("%lf", &c);
	if (a > 0)
		i++;
	if (b > 0)
		i++;
	if (c > 0)
		i++;

	printf("number of positive numbers:%d", i);
	return 0;
}