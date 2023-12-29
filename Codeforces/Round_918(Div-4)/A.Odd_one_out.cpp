#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int t, a, b, c;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        if (a == b) cout << c;
        else if (a == c) cout << b;
        else if (b == c) cout << a;
        cout << endl;
    }
    

    return 0;
}