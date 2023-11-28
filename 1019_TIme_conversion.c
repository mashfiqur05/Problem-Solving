///  Time conversion

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int hour = n / 3600;    /// 1 hour = 3600 second
    n = n % 3600;

    int minute = n / 60;    /// 1 minute = 60 second
    int second = n % 60;

    printf("%d:%d:%d\n", hour, minute, second);

    return 0;
}