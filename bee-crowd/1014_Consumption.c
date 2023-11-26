///   Consumption

#include <stdio.h>

int main()
{
   int distance ;
   double fuel; 

   scanf ("%d %lf", &distance, &fuel);

    double ans = (distance / fuel);

    printf("%.3lf km/l\n", ans);

    return 0;
}