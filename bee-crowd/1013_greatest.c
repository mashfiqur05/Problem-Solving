/// Greatest

#include <stdio.h>

int main()
{
    int a, b, c, greatest;
    scanf("%d %d %d", &a, &b, &c);
    greatest = a;
    if (a < b || a < c)
    {
        if (b < c)
        {
            greatest = c;
        }
        else
        {
            greatest = b;
        }
    }
    printf("%d eh o maior\n", greatest);

    return 0;
}