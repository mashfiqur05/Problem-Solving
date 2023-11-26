///  Salary with Bonus

#include <stdio.h>

int main()
{
    char name[15];
    double salary, sell;

    scanf("%s %lf %lf",&name, &salary, &sell);

    double total = salary + (.15 * sell);

    printf("TOTAL = R$ %.2lf\n", total);

    return 0;
}