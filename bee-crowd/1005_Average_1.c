///  Average 1

#include <stdio.h>

int main()
{
    double A, B;
    double wa = 3.5, wb = 7.5;

    scanf("%lf %lf", &A, &B);

    double w = wa + wb;
    double media = (A * wa + B * wb) / w;
    
    printf("MEDIA = %.5lf\n", media);

    return 0;
}