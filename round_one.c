/*      Problem Statement
Takahashi is solving quizzes. He has easily solved all but the last one.
The last quiz has three choices:
1, 2, and 3.
With his supernatural power, Takahashi has found out that the choices
A and B are both wrong.
Print the correct choice for this problem.

Constraints
Each of the numbers A and B is 1, 2, or 3. A and B are different.   */

#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ans = 6 - (a + b);      /// 1 + 2 + 3 = 6
    printf("%d\n", ans); 

    /* can be solve this way.
    if ((a == 1 || a == 2) && (b == 1 || b == 2))
    {
        printf("3\n");
    }
    else if ((a == 1 || a == 3) && (b == 1 || b == 3))
    {
        printf("2\n");
    }
    else
    {
        printf("1\n");
    }*/
    
    return 0;
}