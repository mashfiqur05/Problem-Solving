///     Age in Days

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int years = n / 365;    ///  1 year = 365 days
    n = n % 365;
    printf("%d ano(s)\n", years);

    int month = n / 30;     ///  1 month = 30 days 
    printf("%d mes(es)\n", month);

    int days = n % 30;     
    printf("%d dia(s)\n", days);

    return 0;
}