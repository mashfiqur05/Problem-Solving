///  Sphere

#include <stdio.h>

int main()
{
    double pi = 3.14159;
    int r;

    scanf("%d", &r);

    double v = (4/3.0) * pi * r * r * r;

    printf("VOLUME = %.3lf\n", v);

    return 0;
}