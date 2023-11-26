///  Salary

#include <stdio.h>

int main()
{
    int number;
    double hour, amountperhour;

    scanf("%d %lf %lf", &number, &hour, &amountperhour);

    double salary = hour * amountperhour;

    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2lf\n", salary);

    return 0;
}
