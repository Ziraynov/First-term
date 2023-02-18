#include <stdio.h>
int main()
{
    int num, j;
    for (num = 11; num <= 32; num++)
    {
        for (j = 2; j <= num; j++)
            if (num % j == 0) break;
        if (j == num)  
        {
            int prime = num * num;

            int pred = prime % 10;
            prime = prime / 10;
            while (prime > 0)
            {
                if (prime % 10 < pred)
                    pred = prime % 10;
                else break;
                prime = prime / 10;
            }
            if (prime == 0)
                printf("%d\n", num);
        }
    }
    return 0;
}