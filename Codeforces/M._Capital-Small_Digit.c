#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);

    int ascii = c;

    if (ascii >= 48 && ascii <= 57)
    {
        printf("IS DIGIT\n");
    }
    else if (ascii >= 65 && ascii <= 90)
    {
        printf("ALPHA\nIS CAPITAL\n");
    }
    else
    {
        printf("ALPHA\nIS SMALL\n");
    }

    return 0;
}