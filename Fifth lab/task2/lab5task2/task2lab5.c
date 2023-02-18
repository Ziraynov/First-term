#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arraytask2lab5.h"
void input_rows(int *n)
{
	int rows;
	printf("imput number of rows ");
	while (scanf_s("%d", &rows)!=1 || getchar()!='\n');
	{
		printf("try againg");
		rewind(stdin);
	}
	*n = rows;
}
void output(int** array, int n,int *m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (*m); j++)
		{
			if (array[i][j] == 0)
			{
				printf("\n");
				break;
			}
			else
			{
				printf("%4d", array[i][j]);
				(*m)++;
			}
		}	
	}
}

int main()
{
	int** array,n,m=1;
	input_rows(&n);
	array = memory(n,m);
	input(array,n,&m);
    output(array, n,&m);
	delete_lowest(array,&n,&m,n);
	printf("new array\n");
	output(array,n, &m);
	free(array);
	return 0;
}
