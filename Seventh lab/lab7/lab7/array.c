#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tasks.h"
void input_row(int* row)
{
    while (!scanf_s("%d", row) || getchar() != '\n' || *row < 2)
    {
        printf("Error,try againg");
        rewind(stdin);
    }
}
void memory_input(char*** string, int row,int key)
{
    if (key == 1)
    {
        *string = (char**)calloc(row, sizeof(char*));
        for (int i = 0; i < row; i++)
        {
            printf("Input %d row: \n", i + 1);
            int pos = 0;
            (*string)[i] = (char*)calloc(1, sizeof(char));
            char ch;
            while (1)
            {
                ch = getchar();
                if (ch == '\n') {
                    (*string)[i][pos] = '\0';
                    break;
                }
                (*string)[i][pos++] = ch;
                if (pos >= 1)
                    (*string)[i] = (char*)realloc((*string)[i], (pos + 1) * 1);
            }

        }
    }
    else
    {
        for (int i = 0; i < row; i++)
            free((*string)[i]);
        free(*string);
    }
}
void memory_size_input(char** string,int *length)
{
    int pos = 0;
    *string = (char*)calloc(1, 1);
    char ch;
    while (1)
    {
        ch = getchar();
        if (ch == '\n') 
        {
            (*string)[pos] = '\0';
            break;
        }
        (*string)[pos] = ch;
        pos++;
         *length= pos;
        if (pos >= 1)
            *string = (char*)realloc(*string, (pos+1) * 1);
    }
}
int if_letter(char string)
{
    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z'))
        return 1;
    return 0;
}
void big_letters(char** string, int length)
{
    int i=0;
    do
    {
        if ((i == 0 && if_letter((*string)[i]) == 1 ) || (if_letter((*string)[i-1]) == 0 && if_letter((*string)[i]) == 1))
        {

            if ((*string)[i] >= 'a' && (*string)[i] <= 'z')
                (*string)[i] = (*string)[i] - 'a' + 'A';
            
               
        }
        i++;
        
    } while (i <=length);
    printf("%s", *string);
}
void imput(int *n, int lnght)
{
    while (!scanf_s("%d", n) || getchar() != '\n' || *n > lnght)
    {
        printf("Error,try againg.");
        rewind(stdin);

    }
}
void numbers_n1_n2(int* N1, int* N2, int lenght1, int lenght2)
{
    printf("Input N1(How many symbols from first string): \n");
    imput(N1, lenght1);
    printf("Input N2(How many symbols from second string): \n");
    imput(N2, lenght2);

}
void new_string(char** string1, char* string2, int N1, int N2,int lenght2)
{
    int k = N2;
    (*string1) = (char*)realloc(*string1, (N1 + N2+1) * sizeof(char));
    for (int i = N1; i <= N1 + k+1; i++)
        (*string1)[i] = string2[lenght2 - (N2--)];
}
