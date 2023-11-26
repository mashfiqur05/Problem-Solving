///  Average 2

#include <stdio.h>

int main()
{
    double A, B, C;
    double wa = 2, wb = 3, wc = 5;

    scanf("%lf %lf", &A, &B);
    scanf("%lf", &C);

    double w = wa + wb + wc;
    double media = (A * wa + B * wb + C * wc) / w;
    
    printf("MEDIA = %.1lf\n", media);

    return 0;
}
