#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
void wana_see_new_array(int* key)
{
	int k;
	printf("\nShow new array?(1 to show,0 to not show)\n");
	while (scanf_s("%d", &k) != 1 && k != 1 && k != 0)
	{
		printf("error");
		rewind(stdin);
	}
	*key = k;
}
void memory(int*** array, int n)
{
	**array = (int*)calloc(n, sizeof(int));
}
void random_elements(int* array,int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		array[i] = rand() % 100;

}
void firstminfound(int* array, int n, int min, int* fmin)
{
	
	for (int i = 0; i < n;i++)
		if (min > array[i])
			min = array[i];
	for(int j=n-1;j>=0;j--)
		if (min == array[j])
		{
			*fmin = j;
			break;
		}
	
}
void lastminfound(int* array, int n, int min, int* l, int f)
{
	for (int i = 0; i < n; i++)
		if (min > array[i] && array[i] != array[f])
			min = array[i];
	for (int i=0;i<n;i++)
		if (min == array[i])
		{
			*l = i;
			break;
		}
	

}
void minimums(int* array, int n, int* fmin, int* lmin)
{
	int min=array[0],tmp,f,l;
	firstminfound(array,n, min, &f);
	lastminfound(array,n, min, &l,f);
	printf("Fmin:%3d(%3d)\n", f+1,array[f]);
	printf("lmin:%3d(%3d)\n", l+1,array[l]);
	if (f > l)
	{
		tmp = f;
		f = l;
		l = tmp;
	}
	*fmin = f;
	*lmin = l;
}
void print_array(int *array, int n, int fmin, int lmin,int *noteven)
{
	int count=0;
	for (int i = 0; i < n; i++)
	{
		if ((i != fmin && i != lmin) && array[i] % 2 == 0)
			printf("%3d ", array[i]);
		if (i == fmin || i == lmin)
			printf("\033[32m%3d \033[0m", array[i]);
		if (i > fmin && i < lmin && array[i] % 2 != 0)
		{
			printf("\033[33m%3d \033[0m", array[i]);
			count++;
		}
		*noteven = count;
		/*printf("%3d", array[i]);*/
	}
}
void sort(int *array_for_sort,int k)
{
	clock_t start, end; double ms;
	//double start_time = clock(),ms;
	int i;
	start = clock();
	for (int j = 1; j < k; j++) {
		int tmp = array_for_sort[j];
		i = j - 1;
		while (i >= 0 && array_for_sort[i] > tmp) {
			array_for_sort[i + 1] = array_for_sort[i];
			i--;
		} 	//	array_for_sort[j];

		array_for_sort[i + 1] = tmp;
	}
	end = clock();
		//double end_time = clock();
	ms = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nTime of sort: %.4f s\n",ms);
}
void new_array(int* array, int fmin, int lmin,int* array_for_sort)
{
	int k = 0;
	for (int i = fmin + 1; i < lmin; i++)
		if (array[i] % 2 != 0)
			array[i] = array_for_sort[k++];
}
void sort_bubble(int* array_for_bubble, int k)
{
	int tmp, noSwap; double ms;
	clock_t end, start;
	start = clock();
	//double start_time = clock();
	for (int i = k - 1; i >= 0; i--)
	{
		noSwap = 1;
		for (int j = 0; j < i; j++)
		{
			if (array_for_bubble[j] > array_for_bubble[j + 1])
			{
				tmp = array_for_bubble[j];
				array_for_bubble[j] = array_for_bubble[j + 1];
				array_for_bubble[j + 1] = tmp;
				noSwap = 0;
			}
		}
		if (noSwap == 1)
			break;
	}
	 end = clock();
	 ms = (double)(end - start)/CLOCKS_PER_SEC;
	 printf("Time for buuble: %.4f s\n",ms);
}
void help_array(int* array, int fmin, int lmin, int* array_for_sort,int noteven,int key,int key2)
{
	int k = 0;
	
	for (int i = fmin + 1; i < lmin; i++)
		if (array[i] % 2 != 0)
			array_for_sort[k++] = array[i];
	if (key == 1)
		sort(array_for_sort, k);
	else
		sort_bubble(array_for_sort, k);
	if(key2==1)
	new_array(array, fmin, lmin, array_for_sort);

}
void first_check(int** array, int n, int** array_for_sort)
{
	int fmin, lmin,noteven,key;
	memory(&array, n);
	random_elements(*array, n);
	minimums(*array, n, &fmin, &lmin);
	print_array(*array, n,fmin,lmin,&noteven);
	memory(&array_for_sort, noteven);
	help_array(*array, fmin, lmin, *array_for_sort,noteven,1,1);
	wana_see_new_array(&key);
	if (key == 1)
	print_array(*array, n,fmin,lmin,&noteven);
	
}
void check_for_1000(int** array, int** array_for_sort, int** array_for_bubble)
{
	int n=1,fmin,lmin,noteven,key;
	number_of_elements(&n);
	memory(&array, n);
	random_elements(*array, n);
	minimums(*array, n, &fmin, &lmin);
	print_array(*array, n, fmin, lmin, &noteven);
	memory(&array_for_sort, noteven);
	memory(&array_for_bubble, noteven);
	help_array(*array, fmin, lmin, *array_for_sort, noteven,1,0);
	help_array(*array, fmin, lmin, *array_for_bubble, noteven,0,1);
	wana_see_new_array(&key);
	if (key == 1)
	print_array(*array, n, fmin, lmin, &noteven);
}
void elements_for_worst(int *array, int n)
{
	int tmp = n;
	for (int i = 1; i < n-1; i++)
	{
		array[i] = tmp * 2 - 1;
		tmp--;
	}
	array[0] = 0;
	

}
void worst_check_1000(int** array, int** array_for_sort, int** array_for_bubble)
{
	int n = 1, fmin, lmin, noteven,key;
	number_of_elements(&n);
	memory(&array, n);
	elements_for_worst(*array, n);
	//random_elements(*array, n);
	minimums(*array, n, &fmin, &lmin);
	print_array(*array, n, fmin, lmin, &noteven);
	memory(&array_for_sort, noteven);
	memory(&array_for_bubble, noteven);
	help_array(*array, fmin, lmin, *array_for_sort, noteven, 1, 0);
	help_array(*array, fmin, lmin, *array_for_bubble, noteven, 0, 1);
	wana_see_new_array(&key);
	if(key==1)
	print_array(*array, n, fmin, lmin, &noteven);
}




































//void memory_of_array(int n, int** array)
//{
//
//	*array = (int*)calloc(n, sizeof(int));
//
//}
//void random_array(int* array, int n)
//{
//	srand(time(NULL));
//	for (int i = 0; i < n; i++)
//		array[i] = rand() % 301 - 150;
//}
//void print_array(int** array, int n, int index_of_firstmin, int index_of_lastmin)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (i != index_of_firstmin && i != index_of_lastmin && (*array)[i] % 2 == 0)
//			printf("%3d ", (*array)[i]);
//		if (i == index_of_firstmin || i == index_of_lastmin)
//			printf("\033[32m%3d \033[0m", (*array)[i]);
//		if (i > index_of_firstmin && i < index_of_lastmin && (*array)[i] % 2 != 0)
//			printf("\033[33m%3d \033[0m", (*array)[i]);
//	}
//}
//void first_and_last_minimum(int* array, int n, int* index_of_firstmin, int* index_of_lastmin)
//{
//	int min = INT_MAX, tmp;
//	for (int i = 0; i < n; i++)
//		if (min > array[i])
//			min = array[i];
//	tmp = min;
//	for (int j = 0; j < n; j++)
//		if (min == array[j])
//		{
//			*index_of_firstmin = j;
//			break;
//		}
//	min = INT_MAX;
//	for (int k = 0; k < n; k++)
//		if (min > array[k] && array[k] != tmp)
//			min = array[k];
//	for (int l = 0; l < (n); l++)
//		if (tmp == array[l])
//		{
//			*index_of_firstmin = l;
//			break;
//		}
//	for (int p = 0; p < (n); p++)
//		if (min == array[p])
//		{
//			*index_of_lastmin = p;
//		}
//}
//void  normal(int* array, int* index_of_firstmin, int* index_of_lastmin)
//{
//	int tmp = 0, f = *index_of_firstmin, l = *index_of_lastmin;
//	if (f > l)
//	{
//		int tmp = f;
//		f = l;
//		l = tmp;
//	}
//	*index_of_firstmin = f;
//	*index_of_lastmin = l;
//	printf("\nNumber of first min: %d(%d)\n", f, array[f]);
//	printf("Number of last min: %d(%d)\n", l, array[l]);
//	l = f = 0;
//}
//void memory_of_array_for_sort(int** array_for_sort)
//{
//	*array_for_sort = (int*)calloc(1, sizeof(int));
//}
//void kar(int** array, int** array_for_sort, int i, int k)
//{
//	*array_for_sort = (int*)realloc(*array_for_sort, k * sizeof(int));
//	(*array_for_sort)[k - 1] = (*array)[i];
//}
//void rules_for_sort(int** array, int index_of_lastmin, int index_of_firstmin, int** array_for_sort, int* k)
//{
//	for (int i = index_of_firstmin + 1; i < index_of_lastmin; i++)
//		if ((*array)[i] % 2 != 0)
//		{
//			kar(array, array_for_sort, i, *k);
//			(*k)++;
//		}
//	(*k)--;
//
//}
//
//void sort(int* array_for_sort, int* k)
//{
//	float start_time = clock();
//	int i;
//	for (int j = 1; j < *k; j++) {
//		int tmp = array_for_sort[j];
//		i = j - 1;
//		while (i >= 0 && array_for_sort[i] > tmp) {
//			array_for_sort[i + 1] = array_for_sort[i];
//			i--;
//		} 		array_for_sort[j];
//
//		array_for_sort[i + 1] = tmp;
//	}
//	float end_time = clock();
//	printf("\nTime of sort:%lf\n\n", end_time - start_time);
//	*k = 1;
//}
//void new_array(int* array, int* array_for_sort, int index_of_firstmin, int index_of_lastmin)
//{
//	int k = 0;
//	for (int i = index_of_firstmin + 1; i < index_of_lastmin; i++)
//	{
//		if (array[i] % 2 != 0)
//		{
//			array[i] = array_for_sort[k];
//			k++;
//		}
//	}
//}
//void sort_bubble(int* array_for_bubble, int p)
//{
//	int tmp, noSwap;
//	float start_time = clock();
//	for (int i = p - 1; i >= 0; i--)
//	{
//		noSwap = 1;
//		for (int j = 0; j < i; j++)
//		{
//			if (array_for_bubble[j] > array_for_bubble[j + 1])
//			{
//				tmp = array_for_bubble[j];
//				array_for_bubble[j] = array_for_bubble[j + 1];
//				array_for_bubble[j + 1] = tmp;
//				noSwap = 0;
//			}
//		}
//		if (noSwap == 1)
//			break;
//	}
//	float end_time = clock();
//	printf("time for buuble: %f", end_time - start_time);
//
//}
////void check_for_1000(int** array,int **array_for_sort,int array_for_bubble,int* n, int* index_of_firstmin, int* index_of_lastmin)
////{
////	int k;
////	printf("\ncheck time for 1000 or 10000 elements?\n");
////	while (scanf_s("%d", &k) != 1 || k != 1000 && k != 10000 || getchar() != '\n')
////	{
////		printf("Error,try againg");
////		rewind(stdin);
////	}
////	*n = k;
////	int p = 1;
////	memory_of_array(k, &array);
////	random_array(array, k);
////	first_and_last_minimum(array, k, &index_of_firstmin,&index_of_lastmin);
////	normal(array, &index_of_firstmin, &index_of_lastmin);
////	print_array(&array, k, index_of_firstmin, index_of_lastmin);
////	memory_of_array_for_sort(&array_for_sort);
////	memory_of_array_for_sort(&array_for_bubble);
////	rules_for_sort(array, index_of_firstmin, index_of_lastmin, array_for_sort, &p);
////	rules_for_sort(array, index_of_firstmin, index_of_lastmin, array_for_bubble , &p);
////	sort(array_for_sort, &p);
////	sort_bubble(array_for_bubble, p);
////	new_array(*array,array_for_bubble, index_of_firstmin, index_of_lastmin);
////	print_array(&array, n, index_of_firstmin, index_of_lastmin);
////}
//
//
//
