#include <stdio.h>
#include <time.h>

int main()
{
	int array1[10], array2[10], choice, i, j; //i first array; j second array
	printf("Choose a method for entering elements:\nrandom-1;by myself-2\n");
	while (scanf_s("%d", &choice) != 1 || choice != 1 && choice != 2)
	{
		printf("error,try againg ");
		rewind(stdin);
	}
	if (choice == 1)
	{
		i = 0;
		srand(time(NULL));
		for (; i < 10; i++)
		{
			array1[i] = rand() % 20 - 10;

			printf(" %d ", array1[i]);
		}
		printf("\n");
		for (j = 0; j < 10; j++)
		{

			array2[j] = rand() % 20 - 10;
			printf(" %d ", array2[j]);
		}


	}
	else
	{
		for (i = 0; i < 10; i++)

		{
			printf("input %d element of array1: ", i + 1);
			while (scanf_s("%d", &array1[i]) != 1)
			{
				printf("try againg,input\n");
				rewind(stdin);
			}
		}

		for (j = 0; j < 10; j++)
		{
			printf("input %d element of array2: ", j + 1);
			while (scanf_s("%d", &array2[j]) != 1)
			{
				printf("try againg, input\n");
				rewind(stdin);
			}
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", array1[i]);
		}
		printf("\n");
		for (j = 0; j < 10; j++)
		{
			printf("%d ", array2[j]);
		}
		printf("\n");
	}



	long mini = 1E9;
	int isFinded = 0;

	for (i = 0; i < 10; i++)
	{
		int isWas = 0;
		for (j = 0; j < 10; j++)
		{
			if (array1[i] == array2[j])
				isWas = 1;
			break;
		}

		if (isWas == 0)
		{
			if (array1[i] < mini) mini = array1[i];
			isFinded = 1;
		}

	}
	printf("\n");

	if (isFinded == 1) {
		printf("%d\n", mini);
	}
	else {
		printf("Not founded\n");
	}




	return 0;

}