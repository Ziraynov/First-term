#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"array.h"
void vvod(int *k)
{
	int p;
	while (scanf_s("%d", &p) != 1 || getchar() != '\n')
	{
		printf("Error,try againg");
		rewind(stdin);
	}
	*k = p;
}
void size_of_matrix(int *n,int *m)
{
	int N=0, M=0;
	printf("imput number of rows: ");
	vvod(&N);
	printf("imput number of colones: ");
	vvod(&M);
	*n = N; *m = M;

}
//void memory(int*** array, int n, int m)
//{
//	*array = (int**)calloc(n+1, sizeof(int*));
//	for (int i = 0; i < n+1; i++)
//	{
//		(*array)[i] = (int*)calloc(m, sizeof(int));
//	}
//}
//void random(int** array, int n, int m)
//{
//	srand(time(0));
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			array[i][j] = rand() % 100;
//}
//void print_array(int** array, int n, int m)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			printf("%3d ", array[i][j]);
//		printf("\n");
//	}
//	
//}
//void sum1(int** array, int n, int m)
//{
//	int sum = 0, p = 0;
//	for (int j = 0; j < m; j++)
//	{
//		for (int i = 0; i < n; i++)
//			sum += array[i][j];
//		for (int i = n; i < n + 1; i++)
//			array[i][p] = sum;
//		p++;
//		sum = 0;
//	}
//}
//void hoarsort(int** array, int n, int m)
//{
//
//}
int main()
{
	int** array,N,M;
	size_of_matrix(&N, &M);
	memory(&array,N,M,0);
	random(array, N, M);
	print_array(array, N, M);
	sum1(array, N, M);
	printf("\nSum of elements of each colonge in the last row:\n\n");
	print_array(array, N+1, M);
	hoarsort(array, 0, M-1,N);
	printf("\nSorted array:\n");
	print_array(array, N + 1, M);
	memory(&array, N, M, 1);
	return 0;
}