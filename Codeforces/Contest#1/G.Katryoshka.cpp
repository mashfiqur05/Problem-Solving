#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    long long e, m, b;
    cin >> e >> m >> b;

    if (e <= b && e <= m) cout << e;
    else if (m <= e && m <= b) 
    {
        if ((b - m) <= (e - m) / 2) cout << m + (b - m);
        else cout << m + (e - m) / 2;
    }
    else if (b <= e && b <= m) cout << b;

    return 0;
}