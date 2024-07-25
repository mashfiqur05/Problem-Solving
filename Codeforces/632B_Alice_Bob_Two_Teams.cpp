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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        string s;
        cin >> s;

        int sum = 0, rep = 0, tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B') sum += v[i];
        }
        int ans = sum;

        for (int i = 0; i < 2; i++)
        {
            int a = 0, b = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j] == 'A') a += v[j];
                else b += v[j];

                ans = max (ans, sum - b + a);
               // cout <<"ans = " << ans << " Alice " << a << " BOB " << b << " sum " << sum << endl;
            }
            reverse (all (v));
            reverse (all (s));
        }

        cout << ans << endl;
    }
    
    return 0;
}