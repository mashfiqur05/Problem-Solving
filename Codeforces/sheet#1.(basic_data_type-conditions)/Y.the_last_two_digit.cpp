/// Given 4 numbers A, B, Cand D.Print the last 2 digits from their Multiplication.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    while (a >= 100) a = a % 100;
    while (b >= 100) b = b % 100;
    while (c >= 100) c = c % 100;
    while (d >= 100) d = d % 100; 

    int multiples = a * b * c * d;
    int ans = multiples % 100;

    if (ans < 10) cout << "0" << ans;
    else cout << ans;

    return 0;
}