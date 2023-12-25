/// A number of two digits is lucky if one of its digits is divisible by the other.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n;
    cin >> n;

    int digit1 = n % 10;
    int digit2 = n / 10;

    if (digit1 % digit2 == 0 || digit2 % digit1 == 0) cout << "YES";
    else cout << "NO";

    return 0;
}