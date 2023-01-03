#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f1(int*);

int i = 1;

int main()
{
    int i = 3;
    while(i <= 5)
    {
        f1(&i);
        printf("%d ",i);
    }
    return 0;
}

void f1(int *a)
{
    static int x = 0;
    *a = ++x + i;
    x++;
}