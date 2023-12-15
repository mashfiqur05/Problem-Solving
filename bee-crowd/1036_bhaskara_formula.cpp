#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(5); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    double a, b, c;
    cin >> a >> b >> c;

    double calcular = (b * b) - 4 * a * c;

    if (calcular < 0 || (2 * a) == 0)
    {
        cout << "Impossivel calcular" << endl;
    }
    else
    {
        double r1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        double r2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("R1 = %.5lf\nR2 = %.5lf\n", r1, r2);
    }

    return 0;
}