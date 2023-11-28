///  Fuel  Spent

#include <stdio.h>

int main()
{
    int hours, speed;

    scanf("%d %d", &hours, &speed);

    double distance = 1.0 * hours * speed;
    
    printf("%.3lf\n", (distance / 12.0));

    return 0;
}