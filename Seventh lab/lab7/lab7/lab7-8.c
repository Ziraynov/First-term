#include <stdio.h>
#include <stdlib.h>
#include "tasks.h"
int main(int argc,char** argv)
{
	int key = 0;
	while (1)
	{
		menu();
		number_for_task(&key);
		void (*taskss[3]) (int, char**) = { task1, task2, stop };
		((*taskss[key - 1])(argc, argv));
	}
	return 0;
}