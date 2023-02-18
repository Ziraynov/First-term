#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
int** memory(int size)
{
    int** mas;
    mas = (int**)calloc(size, sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        *(mas+i) = (int*)calloc(size, sizeof(int));
    }
    return mas;
}
void input_array(int **array,int size)
{
    srand(time(NULL));
    int n;
    printf("How input?\nRandom=0\nBy yourself=1\n");
    while (scanf_s("%d", &n) != 1 || getchar() != '\n' || n != 1 && n != 0)
    {
        printf("Error,try againg");
        rewind(stdin);
    }
    if (n == 0)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                *(*(array + i) + j) = rand() % 201 - 100;
    else
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int lastchar;
                while (scanf_s("%d", &(*(*(array + i) + j))) != 1 || (lastchar = getchar()) != '\n' && lastchar != ' ')
                {
                    printf("Error,try againg");
                    rewind(stdin);
                }   
            }
        }
}
void print_array(int **array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%4d", *(*(array + i) + j));
        }
        printf("\n");
    }
}
void shift(int** array, int size)
{
    for (int j = 0; j < size; j++)
    {
        int tmp = array[0][j];
        for (int i = 0; i < size-1; i++)
        {
           array[i][j] =array[i+1][j];
           
        }
        array[size - 1][j] = tmp;
    }

}