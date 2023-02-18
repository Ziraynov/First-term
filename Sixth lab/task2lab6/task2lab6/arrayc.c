#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"array.h"
void clear_memory(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
}
void memory(int*** array, int n, int m, int k)
{
	n++;
	if (k == 0)
	{
		*array = (int**)calloc(n, sizeof(int*));
		for (int i = 0; i < n; i++)
		{
			(*array)[i] = (int*)calloc(m, sizeof(int));
		}
	}
	else
		clear_memory(*array, n);
}
void random(int** array, int n, int m)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			array[i][j] = rand() % 100;
}
void print_array(int** array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%5d ", array[i][j]);
		printf("\n");
	}

}
void sum1(int** array, int n, int m)
{
	int sum = 0, p = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
			sum += array[i][j];
		for (int i = n; i < n + 1; i++)
			array[i][p] = sum;
		p++;
		sum = 0;
	}
}
int sum(int** array, int n,int m)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += array[n][m];
	return sum;

}
void hoarsort(int **array, int n, int m,int N)
{
	int  f = n, l = m, tmp, base = sum(array,N,(l+f)/2);
	
	while (f <= l)
	{
		for (; sum(array, N, f)> base; f++);
		for (; sum(array, N, l) < base; l--);
		if (f <= l)
		{
			for (int i = 0; i < N+1; i++)
			{
				tmp = array[i][l];
				array[i][l] = array[i][f];
				array[i][f] = tmp;
			}
			f++;
			l--;
		}
	}
	if (n < l) hoarsort(array, n, l,N);
	if (f < m) hoarsort(array, f, m,N);
}

