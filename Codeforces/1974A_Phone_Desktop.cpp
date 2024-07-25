#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

//const int MX = 123;
//int arr[MX];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int x, y;
        cin >> x >> y;

        int need1;
        if (y % 2 == 0) need1 = y / 2;
        else need1 = y / 2 + 1;
//cout << need1 << endl;
        int khali = need1 * 15 - y * 4;
        if (khali >= x) cout << need1 << endl;
        else 
        {
            int need2 = x - khali;
            if (need2 % 15 == 0) cout << need1 + (need2 / 15) << endl;
            else  cout << need1 + (need2 / 15) + 1 << endl;
        }
    }
    
    return 0;
}   