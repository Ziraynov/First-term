#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arraytask2lab5.h"

int** memory(int n, int m) {
    int** arr;
    arr = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)calloc(m, sizeof(int));
    }
    if (arr == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    return arr;
}
void input(int **array, int n, int* m)
{
    printf("Imput elements,if lement=0 its mew row\n");
    for (int i = 0; i < n; i++)
    {
		printf("imput %d row", i + 1);
        for (int j = 0; j < (*m); j++)
        {
            int lastchar;
            while (scanf_s("%d", &array[i][j]) != 1 || (lastchar = getchar()) != '\n' && lastchar != ' ' || array[i][j]<0)
            {
                printf("Error,try againg");
                rewind(stdin);
                
            }
            if (array[i][j] == 0 )
                break;
            if (array[i][j] != 0)
            {
                (*m)++;
                array[i] = (int*)realloc(array[i], (*m) * sizeof(int));
            }
        }
		*m = 1;
    }
}
void delete_lowest(int** array, int* retn, int* m, int n)
{
	int min = INT_MAX, cnt3=0, cnt = 0, p = n,tmp=*m;
	for (int i = 0; i < n; i++)
	{
		if (cnt%2 == 1  )
		{
			for (int j = 0; j < (*m); j++)
			{
				if (array[i][j] == 0)
					break;
				else
				{
					(*m)++;
					if (min > array[i][j])
						min = array[i][j];
					cnt3++;
				}
			}
			(*m)=1;
			if (cnt3 >2)
			{
				for (int j = 0; j < (*m); j++)
				{
					
					if (array[i][j] == min)
					{
						for (int p = j; j < tmp; p++)
						{
							array[i][p] = array[i][p + 1];
							tmp++;
							if (array[i][p + 1] == 0)
								break;
						}
						j--;
						(* m)--;
				
					}
					(*m)++;
					if (array[i][j] == 0)
						break;
					
				}
				array[i] = (int*)realloc(array[i], (*m) * sizeof(int));

			}
		}
		cnt++;
		cnt3 = 0;
		min = INT_MAX;
		*m = 1;
	}
	*retn = p;
}