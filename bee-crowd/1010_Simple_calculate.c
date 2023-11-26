///  Simple Calculate

#include <stdio.h>

int main()
{
    int p1, p2, unit1, unit2;
    double price1, price2;

    scanf("%d %d %lf\n", &p1, &unit1, &price1);
    scanf("%d %d %lf", &p2, &unit2, &price2);

    double total1 = unit1 * price1;
    double total2 = unit2 * price2;

    printf("VALOR A PAGAR: R$ %.2lf\n", total1 + total2);    

    return 0;
}