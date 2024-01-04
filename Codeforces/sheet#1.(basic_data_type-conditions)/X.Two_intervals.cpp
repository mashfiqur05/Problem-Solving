/// Given the boundaries of 2 intervals. Print the boundaries of their intersection.

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

    if (b < c || d < a) cout << "-1";
    else if (a == c)
    {
        if (b < d) cout << a << " " << b;
        else if (d < b) cout << a << " " << d;
        else cout << a << " " << b;     /// for b == d
    }
    else if (a < c)
    {
        if(b < d) cout << c << " " << b;
        else if (d < b) cout << c << " " << d;
        else cout << c << " " << d;     /// for b == d
    }
    else if (c < a)
    {
        if (b < d) cout << a << " " << b;
        else if (d < b) cout << a << " " << d;
        else cout << a << " " << d;     /// for b == d;
    }

    return 0;
}