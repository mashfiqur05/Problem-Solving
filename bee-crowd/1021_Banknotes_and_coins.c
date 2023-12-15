///     Banknotes and Coins

#include <stdio.h>

int main()
{
    double n;
    scanf("%lf", &n);

    /// calculate number of 100 tk notes
    int n100 = n / 100;
    n = n - (n100 * 100);
    printf("NOTAS:\n%d nota(s) de R$ 100.00\n", n100);

    /// calculate number of 50 tk notes
    int n50 = n / 50;
    n = n - (n50 * 50);
    printf("%d nota(s) de R$ 50.00\n", n50);

    /// calculate number of 20 tk notes
    int n20 = n / 20;
    n = n - (n20 * 20);
    printf("%d nota(s) de R$ 20.00\n", n20);

    /// calculate number of 10 tk notes
    int n10 = n / 10;
    n = n - (n10 * 10);
    printf("%d nota(s) de R$ 10.00\n", n10);

    /// calculate number of 5 tk notes
    int n5 = n / 5;
    n = n - (n5 * 5);
    printf("%d nota(s) de R$ 5.00\n", n5);

    /// calculate number of 2 tk notes
    int n2 = n / 2;
    n = n - (n2 * 2);
    printf("%d nota(s) de R$ 2.00\n", n2);

    printf("MOEDAS:\n");

    /// calculate number of coins of 1.00
    int c1 = n / 1;
    n = n - (c1 * 1);
    printf("%d moeda(s) de R$ 1.00\n", c1);

    /// calculate number of coins of 0.50
    int c50 = n / .50;
    n = n - (c50 * .50);
    printf("%d moeda(s) de R$ 0.50\n", c50);

    /// calculate number of coins of 0.25
    int c25 = n / .25;
    n = n - (c25 * .25);
    printf("%d moeda(s) de R$ 0.25\n", c25);

    /// calculate number of coins of 0.10
    int c10 = n / .10;
    n = n - (c10 * .10);
    printf("%d moeda(s) de R$ 0.10\n", c10);

    /// calculate number of coins of 0.05
    int c05 = n / .05;
    n = n - (c05 * .05);
    printf("%d moeda(s) de R$ 0.05\n", c05);

    /// calculate number of coins of 0.01
    int c01 = n * 100;
    printf("%d moeda(s) de R$ 0.01\n", c01);


    return 0;
}