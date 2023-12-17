#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    double a, b, c,largest;
    cin >> a >> b >> c;     /// input 3 float.

    /// determine the largest side of the triangle.
    if (a > b && a > c) largest = a;
    else if (b > a && b > c) largest = b;
    else largest = c;
    
    double sum = a + b + c;
    /// check triangle or not.
    if ((sum - largest) > largest)      /// check triangle or not.
    {
        printf("Perimetro = %.1lf\n", sum);
    }
    else    ///otherwise calculate area of trapezium.
    {
        double area = .5 * (a + b) * c;
        printf("Area = %.1lf\n", area);
    }

    return 0;
}