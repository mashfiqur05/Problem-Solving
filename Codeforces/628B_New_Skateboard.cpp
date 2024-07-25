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
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;

        int ans = 0;
        int sz = s.size();

        for (int i = 0; i < sz; i++)
        {
            if ((s[i] - '0') % 4 == 0) ans++;
        }
        //cout << ans << endl;

        for (int i = 0; i < sz - 1; i++)
        {
            int dig1 = s[i+1] - '0';
            int dig2 = s[i] - '0';
            int tmp = dig2 * 10 + dig1;

            if (tmp % 4 == 0) ans += (i + 1);
        }

        cout << ans << endl;
    }
    
    return 0;
}