/// Given 3 numbers A, B and C, Print the minimum and the maximum numbers.

#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int max, min;
    if (b >= c && b >= a)
    {
        max = b;
    }
    else if (c >= a && c >= b)
    {
        max = c;
    }
    else
        max = a;

    if (b <= c && b <= a)
    {
        min = b;
    }
    else if (c <= a && c <= b)
    {
        min = c;
    }
    else
        min = a;

    printf("%d %d\n", min, max);

    return 0;
}