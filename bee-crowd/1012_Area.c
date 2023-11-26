///  Area

#include <stdio.h>

int main()
{
    double a, b, c;
    double pi = 3.14159;

    scanf("%lf %lf %lf", &a, &b, &c);

    double triangle = .5 * a * c;
    double circle = pi * c * c;
    double trapezium = .5 * (a + b) * c;
    double square = b * b;
    double rectangle = a * b;

    printf ("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", triangle, circle, trapezium, square, rectangle);
    
    return 0;
}