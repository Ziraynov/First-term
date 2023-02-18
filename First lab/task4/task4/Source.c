#include <stdio.h>
int main()
{
	int n;
	printf_s("number of month: ");
	scanf_s("%d", &n);
	if (n == 1 || n == 2 || n == 12)
		printf("winter");
	if (n == 3 || n == 4 || n == 5)
		printf("spring");
	if (n == 6 || n == 7 || n == 8)
		printf_s("summer");
	if (n == 9 || n == 10 || n == 11)
		printf_s("autumn");
	if (n <= 0 || n > 12)
		printf("error");

	return 0;

}