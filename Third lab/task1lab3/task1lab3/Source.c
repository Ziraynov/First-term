#include <stdio.h>
#include <time.h>
int main()
{
	int choice, multiplic = 1, i, sum = 0, j = 0, k = 0;
	int array[100];
	int n;
	printf("enter the number of array elements ");
	while (scanf_s("%d", &n) != 1 || n > 100 || n < 1)
	{
		printf("try again \n");
		rewind(stdin);
	}
	printf("Choose a method for entering elements:\nrandom-1;by myself-2\n");
	while (scanf_s("%d", &choice) != 1 || choice != 1 && choice != 2)
	{
		printf("error,try againg ");
		rewind(stdin);
	}
	if (choice == 1)
	{
		int i = 0;
		srand(time(NULL));
		for (; i < n; i++)
		{
			array[i] = rand() % 100 - 50;


			printf(" %d ", array[i]);
		}
		printf("\n");
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			printf("input %d element of array", i + 1);
			while (scanf_s("%d", &array[i]) != 1)
			{
				printf(" input %d element of array \n", i + 1);
				rewind(stdin);
			}
		}
		for (i = 0; i < n; i++)
			printf("%d ", array[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			multiplic *= array[i];

		}

	}
	printf("product of even numbers: %d\n", multiplic);
	for (i = 0; i < n; i++)
	{
		if (array[i] == 0)
		{
			j = i;
			break;
		}

	}
	for (i = n - 1; i >= 0; i--)
	{
		if (array[i] == 0)

		{
			k = i;
			break;
		}
	}
	for (j; j < k; j++)
	{
		sum += array[j];
	}

	printf("sum between zeros: %d\n ", sum);
	return 0;
}