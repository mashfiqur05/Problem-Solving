/* One day, Ali Baba had an easy puzzle that he couldn't solve. The puzzle consisted of 4numbers and his task was tocheck whether
he could get the fourth number using arithmetic operators (+,−,×)between the other three numbers; so that each operator is used only once.*/

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

    long long e, f, g, h, i, j;

    e = a + b - c;
    f = a + b * c;
    g = a - b + c;
    h = a - b * c;
    i = a * b + c;
    j = a * b - c;

    if (d == e || d == f || d == g || d == h || d == i || d == j) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}