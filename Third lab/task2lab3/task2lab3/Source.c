#include <stdio.h>
#include <time.h>
int main()
{
	int  n, choice, i;
	int array[100];
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
			array[i] = rand() % 20 - 10;


			printf(" %d ", array[i]);
		}
		printf("\n");
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			printf("input %d element of array ", i + 1);
			while (scanf_s("%d", &array[i]) != 1)
			{
				printf("try again. \n");
				printf("input %d element of array\n", i + 1);
				rewind(stdin);
			}

		}
		for (i = 0; i < n; i++)
		{
			printf("%d ", array[i]);
		}
	}
	int position = 0;
	int answerarray[200];
	for (i = 0; i < n; i++)
	{
		answerarray[position++] = array[i];
		if (array[i] % 2 == 0)
		{
			answerarray[position++] = 0;
		}
	}
	printf("\n");

	for (i = 0; i < position; i++)
	{
		printf("%d ", answerarray[i]);
	}

	return 0;
}
