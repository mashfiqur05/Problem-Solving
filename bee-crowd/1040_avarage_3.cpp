#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    double a, b, c, d;
    cin >> a >> b >> c >> d ;   /// input four double.

    /// calculate average using weights formula.
    double average = ((2 * a + 3 * b + 4 * c + 1 * d) / 10);

    /// implement the conditions by using if else loop.
    if (average > 7.0)
    {
        printf("Media: %.1lf\nAluno aprovado.\n", average);
    }
    else if (average < 5.0)
    {
        printf("Media: %.1lf\nAluno reprovado.\n", average);
    }
    else
    {
        double e;
        cin >> e;
        double final = (average + e) / 2;
        printf("Media: %.1lf\nAluno em exame.\n", average);
        printf("Nota do exame: %.1lf\nAluno aprovado.\nMedia final: %.1lf\n", e, final);
    }
    /// if average is between 5 and 6.9 then take another input number and average it with previous answer.  

    return 0;
}