#include <stdio.h>
int temp, year;
int main()
{
	int money = 1000;
	for (temp = money; temp <= money * 2; temp = temp * 1.03)
	{
		year += 1;
	}
	printf("%d", year);
	return 0;
}