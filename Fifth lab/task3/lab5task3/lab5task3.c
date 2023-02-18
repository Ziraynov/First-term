#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
void size_of_matrix(int *size)
{
	int n;
	printf("Imput size of matrix");
	while (scanf_s("%d", &n) != 1 || getchar() != '\n' || n<2)
	{
		printf("Error,try againg");
		rewind(stdin);
	}
	*size = n;
}
int main()
{
	int size,**array;
	
	size_of_matrix(&size);
	array = memory(size);
	input_array(array, size);
	print_array(array, size);
	shift(array, size);
	printf("\n");
	print_array(array, size);
	free(array);
	return 0;
}