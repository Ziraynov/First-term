#include <stdio.h>
#include "array.h"
#include <time.h>
void number_of_elements(int* n)
{
    printf("Number of elements?\n");
    int number;
    while (scanf_s("%d", &number) != 1 || number < 0 || getchar() != '\n')
    {
        printf("Error,try againg");
        rewind(stdin);
    }
    *n = number;
}
void how_imput(int* choice)
{
    printf("How imput?\nBy yourself-1\nRandom-0\n");
    int n;
    while (scanf_s("%d", &n) != 1 || n != 1 && n != 0 || getchar() != '\n')
    {
        printf("try againg");
        rewind(stdin);
    }
    *choice = n;
}
void all_negative(int n)
{
    if (n == 0)
        printf("All negative \n");
    else
        printf("\nThis is new array: \n");
}
int main()
{
    int* mas = NULL;
    int n, choice;
    how_imput(&choice);
    number_of_elements(&n);
    mas = memory(n);
    scanf_array_or_random(n, mas, choice);
    print_array(n, mas);
    delete_elements(mas, n, &n);
    all_negative(n);
    print_array(n, mas);
    free(mas);
    return 0;
}