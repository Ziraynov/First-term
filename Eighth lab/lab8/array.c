#include<stdio.h>
#include<stdlib.h>
#include"array.h"

int len(char* str)
{
	int i = 0, n;
	while (*(str + i) != '\0')
	{
		i++;
	}
	n = i;
	return n;
}
int size_max_word(char* str)
{
	int max_size_word = 0, size_word=0, number_word = 0;
	for (int i = 0; i < len(str) + 1; i++)
	{
		if ((*(str + i) >= 'A' && *(str + i) <= 'Z') || (*(str + i) >= 'a' && *(str + i) <= 'z'))
		{
			int j = i;
			while (((*(str + j) >= 'A' && *(str + j) <= 'Z') || (*(str + j) >= 'a' && *(str + j) <= 'z')))
			{
				size_word++;
				j++;
			}
			number_word++;
			if (number_word == 1)
				max_size_word = size_word;
			else {
				if (max_size_word < size_word)
				{
					max_size_word = size_word;
				}
			}
			i = j + 1;
			size_word = 0;
		}
	}
	return max_size_word;
}

void hoar_sort(char **string, int start,int end)
{
    int i=0; int p=0;
    int  first = start, last = end, base = size_max_word(string[(first+last)/2]); char* tmp = 0;
    while (first < last)
    {
        for (; size_max_word(string[first]) > base; first++);
        for (; size_max_word(string[last]) < base; last--);
        if (first <= last)
        {
                tmp = string[last];
                string[last] = string[first];
                string[first] = tmp;
            first++;
            last--;
        }
    }
    if (start < last) hoar_sort(string,start , last);
    if (first < end) hoar_sort(string, first, end);
}
void print_string(char** mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*(mas + i) != NULL)
		{
			printf("%s", *(mas + i));
			printf("\n       ");
		}
	}
}