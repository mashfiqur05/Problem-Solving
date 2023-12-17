/// Given four numbers A, B, C and D. Print the result of the following equation :
///X = (A * B) - (C * D).

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long x = (a * b) - (c * d);
    cout << "Difference = " << x;

    return 0;
}