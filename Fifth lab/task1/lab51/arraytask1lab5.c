#include <stdio.h>
#include "array.h"
#include <stdlib.h>
#include <time.h>
int* memory(int n)
{
    int* mas;
    mas = (int*)calloc(n, sizeof(int));
    return mas;
}
void scanf_array_or_random(int n, int* mas, int choice)
{
    srand(time(NULL));
    if (choice == 1)
    {
        printf("Input your array");
        for (int i = 0; i < n; i++)
        {
            int lastchar;
            while (scanf_s("%d", &(*(mas + i))) != 1 || (lastchar = getchar()) != '\n' && lastchar != ' ')
            {
                printf("Error,try againg");
                rewind(stdin);
            }
        }
    }
    else
        for (int i = 0; i < n; i++)
        {
            *(mas + i) = rand() % 101 - 50;
        }

}
void print_array(int n, int* mas)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4d", *(mas + i));

    }
    printf("\n");
}
void  delete_elements(int* mas, int n, int* retn)
{
    int i,tmp=n;
    for (i = 0; i < n; i++)
    {
        if (*(mas + i) < 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                *(mas + j) = *(mas + j + 1);

            }
            n--;
            i--;
        }
        mas = (int*)realloc(mas, n * sizeof(int));
        
    }
    *retn = n;
}


