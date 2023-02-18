#include <stdio.h>
int A, B;
int main()
{
	printf("vvedite a");
	scanf_s("%d", &A);
	printf("vvedite b");
	scanf_s("%d", &B);
	if (A < B || A < 0 || B < 0)
		printf("error");
	else
	{
		while (B <= A)
		{
			A = A - B;
		}
		printf("dlin = % d", A);
	}
	return 0;

}