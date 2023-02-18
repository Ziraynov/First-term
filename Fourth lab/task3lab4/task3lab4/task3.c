#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void size_of_matrix(int N, int *retN)
{
	printf("enter size of square matrix:");
	while (scanf_s("%d", &N) != 1 || N > 100 || N <=1 || getchar() != '\n')
	{
		printf("error,try againg");
		rewind(stdin);
	}
	*retN = N;
}
int choice1(int choice)
{
	printf("Choose a method for entering elements:\nrandom-1;by yourself-2\n");
	while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2) || getchar() != '\n')
	{
		printf("error,try againg ");
		rewind(stdin);
	}
	return choice;
}
void random(int array[100][100], int i, int j, int N)
{
	srand(time(0));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			array[i][j] = rand() %201 - 100;
			printf("%4d\t ", array[i][j]);
		}
		printf("\n");
	}

}
void personal_input(int array[100][100], int i, int j,int N)
{
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("input %d %d :", i + 1, j + 1);
			while (scanf_s("%d", &array[i][j]) != 1 || getchar() != '\n' || array[i][j]>999999)
			{
				printf("error,try againg ");
				rewind(stdin);
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%4d ", array[i][j]);
		}
		printf("\n");
	}
}
void max_element(int array[100][100], int i, int j, int sum, int N,int flag)
{
	int n = N;
	for (j = N-1;j>=N-N/2; j--)
	{
		for (i =flag; i < n; i++)
		{
			sum += array[i][j];
	    }
		n--;
		flag++;
    }
	if (N % 2 == 1)
	{
		sum += array[N / 2][N / 2];
	}
	printf("Sum of elements: %d", sum);
}
int main()
{
	int array[100][100], choice = 0, N = 0, i = 0, j = 0,  sum = 0,flag=0;
	size_of_matrix(N,&N);
	choice = choice1(choice);
	if (choice == 1)
	{
		random(array, i, j,N);
	}
	else
	{
		personal_input(array, i, j,N);
	}
	max_element(array, sum, i, j, N,flag);
	return 0;
}