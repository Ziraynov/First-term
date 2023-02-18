
#include <stdio.h>
#include <stdlib.h>
#include "tasks.h"
void menu()
{
    printf("\nTo select a task:\nWrite 1 for the 1st task\nWrite 2 for the 2nd task \nWrite 3 to close program\n");

}
void number_for_task(int* key)
{
    while (!scanf_s("%d",key) || getchar() != '\n' || *key >3 || *key<1)
    {
        printf("Error,try againg");
            rewind(stdin);
    }
}
void stop(int argc,char** argv)
{
    exit(EXIT_SUCCESS);
}
void task1(int argc, char** argv)
{
   
    char* string = NULL; int length;
    printf("Input your string:\n");
    memory_size_input(&string,&length);
    printf("Your string: %s\nNew string: ", string);
    big_letters(&string,length);
    free(string);

}
void task2(int argc, char** argv)
{
    char* string1=NULL, * string2=NULL; int length1, length2, N1,N2;
    printf("Iput your string1:\n");
    memory_size_input(&string1, &length1);
    printf("Your string1: %s\n", string1);
    printf("Imput your string2:\n");
    memory_size_input(&string2, &length2);
    printf("Your string2: %s\n", string2);
    numbers_n1_n2(&N1, &N2,length1,length2);
    new_string(&string1,string2, N1, N2,length2);
    printf("%s", string1);
    free(string1);
    free(string2);
}
