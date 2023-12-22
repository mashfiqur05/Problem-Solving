/// Given a mathematical expression. The expression will be one of the following expressions:A + B = C, A - B = C and A * B = C where A, B, C are three numbers,
/// S is the sign between A and B, and Q the '=' sign Print "Yes" If the expression is Right , Otherwise print the right answer of the expression.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int a, b, c;
    char s, q;
    cin >> a >> s >> b >> q >> c;

    if (s == '+')
    {
        if (a + b == c) cout << "Yes";
        else cout << a + b;
    }
    else if (s == '-')
    {
        if (a - b == c) cout << "Yes";
        else cout << a - b;
    }
    else 
    {
        if (a * b == c) cout << "Yes";
        else cout << a * b;
    }

    return 0;
}