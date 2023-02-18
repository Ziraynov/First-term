#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
void imput(int *n,int p)
{
	int k,key=0;
	if (p == 1)
	{
		printf("\nHow many elemnts you want?(1000,10000,100000)\n");
		key=1;
	}
	if ( key != 1)
	{
		while (scanf_s("%d", &k) != 1 || getchar() != '\n')
		{
			printf("Error,try againg");
			rewind(stdin);
		}
	}
	else
	{
		while (scanf_s("%d", &k) != 1 || getchar() != '\n'  || (k!= 1000 && k != 10000 && k != 100000))
		{
			printf("try againg");
			rewind(stdin);
		}
	}
	*n = k;
}
void number_of_elements(int* number_of_elements)
{
	int n;
	if ((* number_of_elements) == 1)
	{
		imput(&n, 1);
		*number_of_elements = n;
	}
	else
	{
		printf("Number of elements");
		imput(&n, 0);
		(*number_of_elements) = n;
	}
	

}
int main()
{
	int *array, *array_for_sort, *array_for_bubble, n = 0;
	number_of_elements(&n);
	first_check(&array, n, &array_for_sort);
	free(array); free(array_for_sort);
	check_for_1000(&array, &array_for_sort, &array_for_bubble);
	free(array); free(array_for_sort); free(array_for_bubble);
	worst_check_1000(&array, &array_for_sort, &array_for_bubble);
	free(array); free(array_for_sort); free(array_for_bubble);
	return 0;
}
