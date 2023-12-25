/// Given three numbers n, kand a. Identify whether the data type of (n×k)/a is int, long long or double.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    long double a, b, c;
    cin >> a >> b >> c;
    double ans = (a * b ) / c;
    long long result = ans;
    double final = ans - result;

    if (final > 0) cout << "double";
    else if (result >= -2147483648 && result <= 2147483648) cout << "int";
    else cout << "long long";

    return 0;
}