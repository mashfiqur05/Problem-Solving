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
        int n;
        cin >> n;
        vector<int> v(n), ans(n);

        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ans[0] = v[0];

        for (int i = 1; i < n; i++)
        {
            if (v[i] != 0 && (ans[i-1] - v[i]) >= 0)
            {
                f = 0;
                break;
            }

            ans[i] = ans[i-1] + v[i];
        }

        if (f)
        {
            for (auto u : ans) cout << u << ' ';
        }
        else cout << "-1";

        cout << endl;
    }
    
    return 0;
}   